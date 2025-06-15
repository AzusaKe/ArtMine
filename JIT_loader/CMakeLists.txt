file(GLOB JIT_LOADER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(JIT_loader STATIC ${JIT_LOADER_SOURCES})

target_include_directories(JIT_loader PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(JIT_loader PUBLIC
        core
        element
        log
        signal
)