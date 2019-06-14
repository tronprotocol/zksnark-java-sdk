cmake_minimum_required(VERSION 3.10.2)

project(zksnark-java-sdk)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -DNDEBUG")
find_package( Threads )
find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)
include(ExternalProject)

include_directories(include)
include_directories(${JNI_INCLUDE_DIRS})
include_directories(${JAVA_INCLUDE_PATH})
include_directories(${JAVA_INCLUDE_PATH2})

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
		BUILD_COMMAND cargo build
		#		COMMAND cargo build
		--package librustzcash
		--release
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
		"${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/target/release/librustzcash.a"
		${NACL_DIR}/src/libsodium/src/libsodium/.libs/libsodium.a
	)

add_dependencies(zksnarkjni rust)
add_dependencies(zksnarkjni libsodium)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET_TARGET_PROPERTIES( zksnarkjni PROPERTIES LINK_FLAGS "${LINK_FLAGS} -Wl,--wrap=memcpy" )
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	INSTALL(TARGETS zksnarkjni LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../src/main/resources/native-package/linux)
else()
	INSTALL(TARGETS zksnarkjni LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../src/main/resources/native-package/macos)
endif()
