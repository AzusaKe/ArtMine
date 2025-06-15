file(GLOB_RECURSE SIGNAL_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(signal STATIC ${SIGNAL_SOURCES})

target_include_directories(signal PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)