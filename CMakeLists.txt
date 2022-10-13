cmake_minimum_required(VERSION 3.5)
project(grpc-stram-test)
find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
find_package(absl CONFIG REQUIRED)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
find_package(gRPC CONFIG REQUIRED)
set(_GRPC_GRPCPP gRPC::grpc++)

# file(GLOB _ABSEIL "/usr/local/lib/libabsl*")
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

include_directories("${CMAKE_CURRENT_BINARY_DIR}/../protoc-code")
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/../protoc-code/base.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../protoc-code/base.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/../protoc-code/base.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../protoc-code/base.grpc.pb.h")
# hw_grpc_proto
add_library(hw_grpc_proto
  ${hw_grpc_srcs}
  ${hw_grpc_hdrs}
  ${hw_proto_srcs}
  ${hw_proto_hdrs})
target_link_libraries(hw_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

link_directories("/home/server/third/lib")

# Targets greeter_[async_](client|server)
foreach(_target
  BaseServer BaseClient)
  add_executable(${_target} "${_target}.cpp")
  target_link_libraries(${_target}
    hw_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
    # ${_ABSEIL})
endforeach()
