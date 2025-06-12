cmake_minimum_required(VERSION 3.10)
project(fsoft2025_class_1DC_team3)

set(CMAKE_CXX_STANDARD 20)

# Define executable
add_executable(fsoft2025_class_1DC_team3
        Project/main.cpp
        Project/classes.cpp
        Project/functions.cpp
        Project/controllers/AccountController.cpp
        Project/controllers/AdminController.cpp
        Project/data/AccountRepository.cpp
        Project/views/ConsoleView.cpp
        Project/views/ReceiptView.cpp
        Project/services/PasswordServices.cpp
        Project/main2.cpp
        Project/external_functions/functions.cpp
        Project/external_functions/functions.h
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(fsoft2025_class_1DC_team3 PRIVATE nlohmann_json::nlohmann_json)