set(OPERATOR_SOURCES "")
set(OPERATOR_INCLUDE "")

if(WIN32)
    file(GLOB OPERATOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp)
    set(OPERATOR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/windows/include)
else()
    file(GLOB OPERATOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/linux/*.cpp)
    set(OPERATOR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/linux/include)
endif()

add_library(file_operator STATIC ${OPERATOR_SOURCES})

target_include_directories(file_operator PUBLIC ${OPERATOR_INCLUDE})
