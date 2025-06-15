set(INTERACT_SOURCES "")
set(INTERACT_INCLUDE "")
set(INTERACT_LINK_LIBRARIES "")

if(WIN32)
    # Windows 平台下的源文件和头文件路径
    file(GLOB INTERACT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/renderer/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/input/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/glad/src/*.c
    )
    set(INTERACT_INCLUDE
            ${CMAKE_CURRENT_SOURCE_DIR}/windows/renderer/include
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/input/include
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/include
    )
    # Windows 平台下的链接库
    set(INTERACT_LINK_LIBRARIES
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/lib/libglfw3.a
        opengl32
        gdi32
    )
else()
    # Linux 平台下的源文件和头文件路径
    file(GLOB INTERACT_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/linux/*.cpp
    )
    set(INTERACT_INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/linux/include
    )
endif()

# 创建静态库
add_library(interact STATIC ${INTERACT_SOURCES})

# 设置头文件目录
target_include_directories(interact PUBLIC ${INTERACT_INCLUDE})

# 链接库
target_link_libraries(interact PUBLIC core ${INTERACT_LINK_LIBRARIES})