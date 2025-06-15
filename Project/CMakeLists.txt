cmake_minimum_required(VERSION 3.10)
project(fsoft2025_class_1DC_team3)

set(CMAKE_CXX_STANDARD 20)

# Define executable
add_executable(fsoft2025_class_1DC_team3
        Project/controllers/AccountController.cpp
        Project/controllers/AdminController.cpp
        Project/controllers/MainController.cpp
        Project/data/AccountRepository.cpp
        Project/models/BankAccount.cpp
        Project/models/Admin.cpp
        Project/views/ConsoleView.cpp
        Project/views/ReceiptView.cpp
        Project/services/PasswordServices.cpp
        Project/main.cpp
)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(fsoft2025_class_1DC_team3 PRIVATE nlohmann_json::nlohmann_json)