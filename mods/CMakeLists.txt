file(GLOB_RECURSE mods_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(mods STATIC ${mods_SOURCES})

target_include_directories(mods PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mods PUBLIC
        core
        interact
        file_operator
        JIT_loader
        log
        element
        signal
)
