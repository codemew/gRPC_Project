cmake_minimum_required(VERSION 3.5)

project(GrpcExample)

message(STATUS "Using CMake Version : ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}")

# Protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
if(CMAKE_CROSSCOMPILING)
find_package(Protobuf REQUIRED)
else()
find_package(Protobuf REQUIRED)       #Do not use cmake CONFIG, if using old versions of protobuf version
endif()
message(STATUS "Using protobuf version ${protobuf_VERSION}")

# Protobuf-compiler
if(CMAKE_CROSSCOMPILING)
find_program(_PROTOBUF_PROTOC protoc)
else()
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()

# gRPC
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
set(_GRPC_GRPCPP gRPC::grpc++)
if(CMAKE_CROSSCOMPILING)
    find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
else()
    set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
endif()

# # Proto file
get_filename_component(hw_proto "example.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)


# # Generated sources
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/example.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/example.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/example.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/example.grpc.pb.h")
message(STATUS "CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}/")

if(CMAKE_CROSSCOMPILING)

  #skip until grpc v1.24.1 installed.
  add_custom_command(
      OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")
else()
add_custom_command(
      OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")
endif()

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# Targets (client|server)
foreach(_target  client server)
  add_executable(${_target} "${_target}.cpp"    ${hw_proto_srcs}    ${hw_grpc_srcs})
  target_link_libraries(${_target}    ${_REFLECTION}    ${_GRPC_GRPCPP}    ${_PROTOBUF_LIBPROTOBUF})
endforeach()