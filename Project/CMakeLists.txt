cmake_minimum_required(VERSION 3.10)
project(fsoft2025_class_1DC_team3)

set(CMAKE_CXX_STANDARD 20)

# Define executable
add_executable(fsoft2025_class_1DC_team3
        Project/main.cpp
        Project/Bank_Account.cpp
        Project/functions.cpp
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(fsoft2025_class_1DC_team3 PRIVATE nlohmann_json::nlohmann_json)