cmake_minimum_required(VERSION 3.10.2)

project(zksnark-jni)

set(CMAKE_CXX_STANDARD 11)

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
set(zksnark_jni_src LibrustzcashJNIImpl.c)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src zksnark_srcs)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_BINARY_DIR}")
include_directories("${CMAKE_BINARY_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/librustzcash/include")

add_custom_command(
        OUTPUT "${zksnark_jni_include}"
        COMMAND ${Java_JAVAC_EXECUTABLE} -verbose
        -h ${CMAKE_BINARY_DIR}/include
        "${CMAKE_CURRENT_SOURCE_DIR}/../java/src/main/java/org/tron/common/zksnark/Librustzcash.java"
        DEPENDS ${zksnark_jni_include}
)

ExternalProject_Add(
        librustzcash
        DOWNLOAD_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND cargo build COMMAND cargo build --release
        BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash"
        INSTALL_COMMAND ""
        LOG_BUILD ON)

#add_dependencies(zksnarkjni librustzcash)

ADD_LIBRARY(zksnarkjni
	SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/${zksnark_jni_src}
        ${zksnark_src_dependencies}
        ${zksnark_jni_include}
        ${zksnark_srcs}
        )

target_link_libraries(zksnarkjni
	"${CMAKE_CURRENT_SOURCE_DIR}/../rust/librustzcash/target/release/librustzcash.a"
	)
