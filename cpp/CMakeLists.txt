cmake_minimum_required(VERSION 3.10.2)

project(zksnark-java-sdk)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -DNDEBUG")

# macOS specific: Add libc++ include path for Clang
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    execute_process(COMMAND xcrun --show-sdk-path OUTPUT_VARIABLE CMAKE_OSX_SYSROOT OUTPUT_STRIP_TRAILING_WHITESPACE)
    include_directories("${CMAKE_OSX_SYSROOT}/usr/include/c++/v1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")
endif()

find_package( Threads )
find_package(Java REQUIRED)
# find_package(JNI REQUIRED)
include(UseJava)
include(ExternalProject)

include_directories(include)
# include_directories(${JNI_INCLUDE_DIRS})
# include_directories(${JAVA_INCLUDE_PATH})
# include_directories(${JAVA_INCLUDE_PATH2})
include_directories($ENV{JAVA_HOME}/include)
include_directories($ENV{JAVA_HOME}/include/linux)
include_directories($ENV{JAVA_HOME}/include/darwin)

link_directories(lib)

set(zksnark_jni_include org_tron_common_zksnark_Librustzcash_LibrustzcashJNI.h)
set(sodium_jni_include org_tron_common_zksnark_Libsodium_LibsodiumJNI.h)
set(zksnark_jni_src LibrustzcashJNIImpl.cpp)
set(sodium_jni_src LibsodiumJNIImpl.cpp)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src zksnark_srcs)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/tmp)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_BINARY_DIR}")
include_directories("${CMAKE_BINARY_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/librustzcash/include")

set(RUST_BUILD_TARGET "$ENV{RUST_BUILD_TARGET}")
if(NOT RUST_BUILD_TARGET)
	if(APPLE)
		if(CMAKE_OSX_ARCHITECTURES)
			set(RUST_TARGET_ARCH "${CMAKE_OSX_ARCHITECTURES}")
		else()
			set(RUST_TARGET_ARCH "${CMAKE_SYSTEM_PROCESSOR}")
		endif()

		if(RUST_TARGET_ARCH MATCHES ";")
			message(FATAL_ERROR "Universal macOS builds are not supported. Set CMAKE_OSX_ARCHITECTURES to a single architecture or provide RUST_BUILD_TARGET.")
		endif()

		if(RUST_TARGET_ARCH STREQUAL "arm64" OR RUST_TARGET_ARCH STREQUAL "aarch64")
			set(RUST_BUILD_TARGET "aarch64-apple-darwin")
		elseif(RUST_TARGET_ARCH STREQUAL "x86_64")
			set(RUST_BUILD_TARGET "x86_64-apple-darwin")
		else()
			message(FATAL_ERROR "Unsupported macOS architecture '${RUST_TARGET_ARCH}'. Set RUST_BUILD_TARGET explicitly.")
		endif()
	elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
		if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64)$")
			set(RUST_BUILD_TARGET "aarch64-unknown-linux-gnu")
		elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|amd64)$")
			set(RUST_BUILD_TARGET "x86_64-unknown-linux-gnu")
		endif()
	endif()
endif()

set(RUST_BUILD_COMMAND cargo build --package librustzcash --release)
set(RUST_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/target/release/librustzcash.a")
if(RUST_BUILD_TARGET)
	list(APPEND RUST_BUILD_COMMAND --target ${RUST_BUILD_TARGET})
	set(RUST_LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/target/${RUST_BUILD_TARGET}/release/librustzcash.a")
endif()

message(STATUS "Using Rust target: ${RUST_BUILD_TARGET}")

add_custom_command(
		OUTPUT "${zksnark_jni_include}"
		COMMAND ${Java_JAVAC_EXECUTABLE} -verbose
		-h ${CMAKE_BINARY_DIR}/include
		-d ${CMAKE_BINARY_DIR}/tmp
		"${CMAKE_CURRENT_SOURCE_DIR}/../src/main/java/org/tron/common/zksnark/Librustzcash.java"
		DEPENDS ${zksnark_jni_include}
)

add_custom_command(
		OUTPUT "${sodium_jni_include}"
		COMMAND ${Java_JAVAC_EXECUTABLE} -verbose
		-h ${CMAKE_BINARY_DIR}/include
		-d ${CMAKE_BINARY_DIR}/tmp
		"${CMAKE_CURRENT_SOURCE_DIR}/../src/main/java/org/tron/common/zksnark/Libsodium.java"
		DEPENDS ${sodium_jni_include}
)

set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/rust)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
		${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/target
		)

ExternalProject_Add(
		librustzcash
		DOWNLOAD_COMMAND ""
		CONFIGURE_COMMAND ""
		BUILD_COMMAND ${RUST_BUILD_COMMAND}
		BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash"
		INSTALL_COMMAND ""
		LOG_BUILD OFF)

add_custom_target(rust ALL DEPENDS librustzcash)


# libsodium
set (nacl_ver 1.0.15)
ExternalProject_Add(libsodium
		URL https://github.com/jedisct1/libsodium/releases/download/${nacl_ver}/libsodium-${nacl_ver}.tar.gz
		BUILD_IN_SOURCE 1
		CONFIGURE_COMMAND <SOURCE_DIR>/autogen.sh
		BUILD_COMMAND <SOURCE_DIR>/configure --disable-pie
		INSTALL_COMMAND make -j4
		)
ExternalProject_Get_Property(libsodium INSTALL_DIR)
set(NACL_DIR ${INSTALL_DIR})
include_directories(${NACL_DIR}/src/libsodium/src/libsodium/include)
#add_library(nacl_lib STATIC IMPORTED)
#set_property(TARGET nacl_lib PROPERTY IMPORTED_LOCATION ${NACL_DIR}/src/libsodium/src/libsodium/.libs/libsodium.a)

ADD_LIBRARY(zksnarkjni
		SHARED
		${CMAKE_CURRENT_SOURCE_DIR}/src/${zksnark_jni_src}
		${CMAKE_CURRENT_SOURCE_DIR}/src/${sodium_jni_src}
		${zksnark_src_dependencies}
		${zksnark_jni_include}
		${sodium_jni_include}
        ${zksnark_srcs}
		)

target_link_libraries(zksnarkjni
		${CMAKE_THREAD_LIBS_INIT}
		"${RUST_LIBRARY_PATH}"
		${NACL_DIR}/src/libsodium/src/libsodium/.libs/libsodium.a
	)

add_dependencies(zksnarkjni rust)
add_dependencies(zksnarkjni libsodium)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	SET_TARGET_PROPERTIES( zksnarkjni PROPERTIES LINK_FLAGS "${LINK_FLAGS} -Wl,--wrap=memcpy -s" )
	# Linux: support both x86_64 and aarch64
	if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
		INSTALL(TARGETS zksnarkjni LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../src/main/resources/META-INF/native/linux64/aarch64)
	else()
		INSTALL(TARGETS zksnarkjni LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../src/main/resources/META-INF/native/linux64)
	endif()
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
	# macOS: support both x86_64 and arm64
	SET_TARGET_PROPERTIES(zksnarkjni PROPERTIES SUFFIX ".jnilib")

	# Create architecture-specific directories
	if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
		set(MACOS_NATIVE_DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/../src/main/resources/META-INF/native/osx64/aarch64")
	else()
		set(MACOS_NATIVE_DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/../src/main/resources/META-INF/native/osx64")
	endif()

	INSTALL(TARGETS zksnarkjni LIBRARY DESTINATION ${MACOS_NATIVE_DESTINATION})
	INSTALL(CODE
		"execute_process(
			COMMAND /usr/bin/codesign --force --sign - \"${MACOS_NATIVE_DESTINATION}/libzksnarkjni.jnilib\"
			RESULT_VARIABLE codesign_result
		)
		if(NOT codesign_result EQUAL 0)
			message(FATAL_ERROR \"codesign failed with exit code \${codesign_result}: ${MACOS_NATIVE_DESTINATION}/libzksnarkjni.jnilib\")
		endif()"
	)
else()
	message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}. Only Linux and macOS are supported.")
endif()
