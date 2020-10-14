cmake_minimum_required(VERSION 3.8)
set (This MySQLTests)

set(SOURCES
    src/MySQLQuery.cpp
)

add_executable(${This} ${SOURCES})

set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

target_include_directories(${This} PRIVATE ../src)

# target_compile_definitions(${This} PRIVATE CLIPBOARD_REVEAL_OS_API)

target_link_libraries(${This} PUBLIC
    gtest_main
    MySQL
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
