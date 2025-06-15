file(GLOB_RECURSE CORE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(core STATIC ${CORE_SOURCES})

target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/block/include
        ${CMAKE_CURRENT_SOURCE_DIR}/client/include
        ${CMAKE_CURRENT_SOURCE_DIR}/entity/include
        ${CMAKE_CURRENT_SOURCE_DIR}/server/world/include
)
