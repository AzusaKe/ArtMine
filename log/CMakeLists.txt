file(GLOB_RECURSE LOG_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(log STATIC ${LOG_SOURCES})

target_include_directories(log PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)