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
        block_core
)

add_library(water SHARED water.cpp)
if(WIN32)
    target_compile_definitions(water PRIVATE BUILDING_DLL)
else ()
    set_target_properties(water PROPERTIES PREFIX "" SUFFIX ".so")
endif ()
target_link_libraries(water PRIVATE
        core
        interact
        file_operator
        JIT_loader
        log
        element
        signal
        block_core
)

# 构建时移动 water.dll 到 mods 文件夹
add_custom_command(
        TARGET water POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:water> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mods/${CMAKE_SHARED_LIBRARY_PREFIX}water${CMAKE_SHARED_LIBRARY_SUFFIX}
        COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE:water>
        COMMENT "Copy water library to mods folder and remove the original"
)

add_library(air SHARED air.cpp)
if(WIN32)
    target_compile_definitions(air PRIVATE BUILDING_DLL)
else ()
    set_target_properties(air PROPERTIES PREFIX "" SUFFIX ".so")
endif ()
target_link_libraries(air PRIVATE
        core
        interact
        file_operator
        JIT_loader
        log
        element
        signal
        block_core
)

# 构建时移动 air.dll 到 mods 文件夹
add_custom_command(
        TARGET air POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:air> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mods/${CMAKE_SHARED_LIBRARY_PREFIX}air${CMAKE_SHARED_LIBRARY_SUFFIX}
        COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE:air>
        COMMENT "Copy air library to mods folder and remove the original"
)