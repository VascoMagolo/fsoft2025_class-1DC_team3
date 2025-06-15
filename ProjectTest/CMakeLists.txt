cmake_minimum_required(VERSION 3.10)
project(ProjectTest)

set(CMAKE_CXX_STANDARD 20)

# Adicionar Google Test
add_subdirectory(lib)

# Incluir headers do Google Test
include_directories(lib/googletest/include)

# Include the source directories for headers
include_directories(../Project)                # Main project headers
include_directories(../Project/controllers)    # Controller headers
include_directories(../Project/data)          # Data/Repository headers
include_directories(../Project/models)        # Model headers
include_directories(../Project/services)      # Service headers
include_directories(../Project/views)         # View headers

# Encontrar a biblioteca nlohmann_json
find_package(nlohmann_json CONFIG REQUIRED)

# Add source files from your main project
# Automatically find all .cpp files in the Project directory
file(GLOB_RECURSE PROJECT_SOURCES "../Project/*.cpp")

# Exclude main.cpp if it exists (to avoid multiple main functions)
list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Adicionar ficheiros de teste
add_executable(ProjectTest_run
        main.cpp
        test_AccountController.cpp
        test_AccountRepository.cpp
        test_Admin.cpp
        test_AdminController.cpp
        test_BankAccount.cpp
        test_PasswordService.cpp
        ${PROJECT_SOURCES}  # Include the actual source files
)

# Ligar Google Test E nlohmann_json
target_link_libraries(ProjectTest_run
        gtest
        gtest_main
        nlohmann_json::nlohmann_json
)