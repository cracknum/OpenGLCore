cmake_minimum_required(VERSION 3.19...3.22)

project(Testing)

if(NOT TARGET GTest::gtest)
    find_package(gtest CONFIG REQUIRED)
endif()

file(GLOB Test_Files "*.cpp")

add_executable(${PROJECT_NAME} ${Test_Files})
target_link_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${ModuleName}::Context ${ModuleName}::Object GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_add_tests(TARGET ${PROJECT_NAME})

