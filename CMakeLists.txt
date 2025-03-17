cmake_minimum_required(VERSION 3.10)
project(fsoft2025_class_1DC_team2)

set(CMAKE_CXX_STANDARD 20)

# Set MySQL connector paths
set(MYSQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.2/include")
set(MYSQL_LIB_DIR "C:/Program Files/MySQL/MySQL Connector C++ 9.2/lib64/vs14")

# Include MySQL headers
include_directories(${MYSQL_INCLUDE_DIR})
include_directories(${MYSQL_INCLUDE_DIR}/jdbc)

# Link to MySQL library directory
link_directories(${MYSQL_LIB_DIR})

# Define executable
add_executable(fsoft2025_class_1DC_team2
        Project/main.cpp
        Project/classes.cpp
        Project/functions.cpp
        Project/db_connection.cpp)

# Link to MySQL Connector static library
target_link_libraries(fsoft2025_class_1DC_team2
        ws2_32
)

# Ensure DLL is copied to the output folder after build
add_custom_command(TARGET fsoft2025_class_1DC_team2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "C:/Program Files/MySQL/MySQL Connector C++ 9.2/lib64/vs14/mysqlcppconn.dll"
        $<TARGET_FILE_DIR:fsoft2025_class_1DC_team2>)