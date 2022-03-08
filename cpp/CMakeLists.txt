cmake_minimum_required(VERSION 3.20)

project(scivis-openvdb-sample)

set(CMAKE_CXX_STANDARD 14)

add_executable(scivis-openvdb-sample main.cpp)

list(APPEND CMAKE_MODULE_PATH "/usr/local/lib/cmake/OpenVDB")
find_package(OpenVDB REQUIRED)
target_link_libraries(scivis-openvdb-sample OpenVDB::openvdb)