file(GLOB_RECURSE block_core_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(block_core SHARED ${block_core_SOURCES})
target_compile_definitions(block_core PRIVATE BLOCK_CORE_EXPORTS)

target_include_directories(block_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (UNIX AND NOT APPLE)
    set_target_properties(block_core PROPERTIES PREFIX "" SUFFIX ".so")
endif ()