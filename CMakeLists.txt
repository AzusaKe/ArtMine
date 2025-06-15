cmake_minimum_required(VERSION 3.31)
project(ArtMine)

set(CMAKE_CXX_STANDARD 20)

# 设置导出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加include库部分
include_directories(${PROJECT_SOURCE_DIR}/core/include
                    ${PROJECT_SOURCE_DIR}/core/block/include
                    ${PROJECT_SOURCE_DIR}/core/client/include
                    ${PROJECT_SOURCE_DIR}/core/entity/include
                    ${PROJECT_SOURCE_DIR}/core/server/world/include
                    ${PROJECT_SOURCE_DIR}/core/JIT_loader/include
        if(WIN32)
        ${PROJECT_SOURCE_DIR}/renderer/windows/include
        ${PROJECT_SOURCE_DIR}/file_operator/windows/include
        else()
        ${PROJECT_SOURCE_DIR}/renderer/linux/include
        ${PROJECT_SOURCE_DIR}/file_operator/linux/include
        endif()
)

# 查找所有src文件
file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/core/*.cpp
                   ${PROJECT_SOURCE_DIR}/core/block/*.cpp
                   ${PROJECT_SOURCE_DIR}/core/client/*.cpp
                   ${PROJECT_SOURCE_DIR}/core/entity/*.cpp
                   ${PROJECT_SOURCE_DIR}/core/server/world/*.cpp
                   ${PROJECT_SOURCE_DIR}/core/JIT_loader/*.cpp
        if(WIN32)
                   ${PROJECT_SOURCE_DIR}/renderer/windows/*.cpp
                   ${PROJECT_SOURCE_DIR}/file_operator/windows/*.cpp
        else()
                   ${PROJECT_SOURCE_DIR}/renderer/linux/*.cpp
                   ${PROJECT_SOURCE_DIR}/file_operator/linux/*.cpp
        endif()
)

add_executable(ArtMine main.cpp ${SRC_LIST})
