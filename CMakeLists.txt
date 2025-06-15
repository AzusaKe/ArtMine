cmake_minimum_required(VERSION 3.31)
project(ArtMine)

set(CMAKE_CXX_STANDARD 20)

# 输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加资源文件
set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/resources)
set(RESOURCES_OUTPUT_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources)

# 添加子模块
add_subdirectory(core)
add_subdirectory(interact)
add_subdirectory(file_operator)
add_subdirectory(JIT_loader)

# 主程序
add_executable(ArtMine main.cpp)

# 链接子模块
target_link_libraries(ArtMine PRIVATE core interact file_operator JIT_loader)

# 构建时复制 resources 文件夹
add_custom_command(
        TARGET ArtMine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_DIR} ${RESOURCES_OUTPUT_DIR}
        COMMENT "Copy resources folder to output directory"
        
)

# 创建 mods 文件夹
add_custom_command(
        TARGET ArtMine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mods
        COMMENT "Create mods folder in output directory"
)
