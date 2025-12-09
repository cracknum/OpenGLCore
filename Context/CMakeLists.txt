cmake_minimum_required(VERSION 3.19...4.0)

project(Context LANGUAGES CXX)

file(GLOB_RECURSE Header_files "include/*.hpp" "include/*.ipp")
file(GLOB_RECURSE Source_files "src/*.cpp")

if(NOT TARGET spdlog::spdlog)
    find_package(spdlog CONFIG REQUIRED)
endif()

if(NOT TARGET glad::glad)
    find_package(glad CONFIG REQUIRED)
endif()

if(NOT TARGET glfw)
    find_package(glfw3 CONFIG REQUIRED)
endif()

if(NOT "${Source_files}")
    add_library(${PROJECT_NAME} SHARED ${Header_files} ${Source_files})
    target_link_libraries(${PROJECT_NAME}
        PUBLIC spdlog::spdlog
        PRIVATE glad::glad PRIVATE glfw
    )
    add_library(${ModuleName}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
    target_include_directories(${PROJECT_NAME} PUBLIC include)
    export_model(${export_config_file_path} ${PROJECT_NAME})
endif()
