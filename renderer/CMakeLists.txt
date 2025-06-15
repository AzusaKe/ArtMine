set(RENDERER_SOURCES "")
set(RENDERER_INCLUDE "")

if(WIN32)
    file(GLOB RENDERER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp)
    set(RENDERER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/windows/include)
else()
    file(GLOB RENDERER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/linux/*.cpp)
    set(RENDERER_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/linux/include)
endif()

add_library(renderer STATIC ${RENDERER_SOURCES})

target_include_directories(renderer PUBLIC ${RENDERER_INCLUDE})
