file(GLOB_RECURSE element_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp
)

add_library(element STATIC ${element_SOURCES})

target_include_directories(element PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/block/include
        ${CMAKE_CURRENT_SOURCE_DIR}/entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/item/include
)