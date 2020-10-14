cmake_minimum_required(VERSION 3.8)

set(This MySQL)

set(HEADERS
    include/MySQL/MySQL.hpp
)

set(SOURCES
    src/MySQL.cpp
)

# Boost
include_directories(${boost})

# MySQL connector
include_directories(${mysql_connector}/include/jdbc)
link_directories(${mysql_connector}/lib/vs14)

add_library(${This} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${This} PUBLIC include)

target_link_libraries(${This} PUBLIC
    mysqlcppconn
)

set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

add_subdirectory(test)
