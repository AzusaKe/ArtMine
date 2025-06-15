set(RENDERER_SOURCES "")
set(RENDERER_INCLUDE "")
set(RENDERER_LINK_LIBRARIES "")

if(WIN32)
    # Windows 平台下的源文件和头文件路径
    file(GLOB RENDERER_SOURCES 
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/glad/src/*.c
    )
    set(RENDERER_INCLUDE 
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/include 
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/include
    )
    # Windows 平台下的链接库
    set(RENDERER_LINK_LIBRARIES 
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/lib/libglfw3.a
        opengl32
        gdi32
    )
else()
    # Linux 平台下的源文件和头文件路径
    file(GLOB RENDERER_SOURCES 
        ${CMAKE_CURRENT_SOURCE_DIR}/linux/*.cpp
    )
    set(RENDERER_INCLUDE 
        ${CMAKE_CURRENT_SOURCE_DIR}/linux/include
    )
endif()

# 创建静态库
add_library(renderer STATIC ${RENDERER_SOURCES})

# 设置头文件目录
target_include_directories(renderer PUBLIC ${RENDERER_INCLUDE})

# 链接库
target_link_libraries(renderer PUBLIC ${RENDERER_LINK_LIBRARIES})