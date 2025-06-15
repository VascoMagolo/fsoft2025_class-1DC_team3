enable_testing()
include(FetchContent)

# Incluir Google Test via FetchContent
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Incluir todos os ficheiros .cpp de teste, incluindo o main.cpp
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "*.cpp")

add_executable(runTests ${TEST_SOURCES})

# Link com Google Test (sem gtest_main porque já tens main.cpp) e com a lib principal
target_link_libraries(runTests gtest fsoft2025_lib)

include(GoogleTest)
gtest_discover_tests(runTests)