set(RENDERER_SOURCES "")
set(RENDERER_INCLUDE "")

if(WIN32)
    file(GLOB RENDERER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/windows/extern/glad/src/*.c)
    set(RENDERER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/windows/include)
    include_directories(${PROJECT_SOURCE_DIR}/windows/extern/glad/include)
else()
    file(GLOB RENDERER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/linux/*.cpp)
    set(RENDERER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/linux/include)
endif()

add_library(renderer STATIC ${RENDERER_SOURCES})

target_include_directories(renderer PUBLIC ${RENDERER_INCLUDE}
        if(WIN32)
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/include
        endif()
)

target_link_libraries(renderer PUBLIC
        if(WIN32)
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/lib/libglfw3.a
        opengl32
        gdi32
        endif()
)