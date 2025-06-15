cmake_minimum_required(VERSION 3.31)
project(ArtMine)

set(CMAKE_CXX_STANDARD 20)

# 输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子模块
add_subdirectory(core)
add_subdirectory(renderer)
add_subdirectory(file_operator)
add_subdirectory(JIT_loader)

# 主程序
add_executable(ArtMine main.cpp)

# 链接子模块
target_link_libraries(ArtMine PRIVATE core renderer file_operator JIT_loader)
