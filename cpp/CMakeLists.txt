cmake_minimum_required(VERSION 3.10.2)
project(tron_zksnark)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

link_directories(lib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src zksnark_srcs)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    add_definitions(-D_WIN32_WINNT=0x600)
endif()

add_subdirectory(third_party/grpc EXCLUDE_FROM_ALL)
message(STATUS "Using gRPC via add_subdirectory.")

set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP_UNSECURE grpc++_unsecure)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

get_filename_component(zksnark_proto "third_party/protocol/api/zksnark.proto" ABSOLUTE)
get_filename_component(zksnark_proto_dependencies "third_party/protocol/core/*.proto" ABSOLUTE)
get_filename_component(zksnark_proto_path "${zksnark_proto}" PATH)
get_filename_component(zksnark_proto_path "${zksnark_proto_path}" PATH)

# Generated sources
set(zksnark_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/api/zksnark.pb.cc")
set(zksnark_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/api/zksnark.pb.h")
set(zksnark_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/api/zksnark.grpc.pb.cc")
set(zksnark_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/api/zksnark.grpc.pb.h")
#FILE(GLOB zksnark_src_dependencies "${CMAKE_CURRENT_BINARY_DIR}/core/*")

FILE(GLOB proto_files ${CMAKE_CURRENT_SOURCE_DIR}/third_party/protocol/core/*.proto)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/core)
FOREACH(proto_file ${proto_files})
    get_filename_component(proto_file1 "${proto_file}" NAME)
    STRING(REGEX REPLACE "[^/]proto" "" proto_file_name ${proto_file1})
    LIST(APPEND zksnark_src_dependencies "${CMAKE_CURRENT_BINARY_DIR}/core/${proto_file_name}.pb.cc")
    ADD_CUSTOM_COMMAND(
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/core/${proto_file_name}.pb.h" "${CMAKE_CURRENT_BINARY_DIR}/core/${proto_file_name}.pb.cc"
            COMMAND ${_PROTOBUF_PROTOC}
            --cpp_out=${CMAKE_CURRENT_BINARY_DIR}
            -I "${zksnark_proto_path}"
            -I "${CMAKE_SOURCE_DIR}/third_party/grpc/third_party/protobuf/src"
            ${proto_file}
            DEPENDS ${proto_file}
    )
ENDFOREACH(proto_file)
message(STATUS ${zksnark_src_dependencies})

add_custom_command(
        OUTPUT "${zksnark_proto_srcs}" "${zksnark_proto_hdrs}" "${zksnark_grpc_srcs}" "${zksnark_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${zksnark_proto_path}"
        -I "${CMAKE_SOURCE_DIR}/third_party/grpc/third_party/protobuf/src"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
#        "${zksnark_proto_dependencies}"
        "${zksnark_proto}"
        DEPENDS "${zksnark_proto}"
)

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/api")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/core")

add_executable(tron_zksnark main.cpp
        ${zksnark_src_dependencies}
        ${zksnark_proto_srcs}
        ${zksnark_proto_hdrs}
        ${zksnark_grpc_srcs}
        ${zksnark_grpc_hdrs}
        ${zksnark_srcs}
        )
target_link_libraries(tron_zksnark
        ${_GRPC_GRPCPP_UNSECURE}
        ${_PROTOBUF_LIBPROTOBUF}
        -lrustzcash
        )
