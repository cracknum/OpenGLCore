cmake_minimum_required(VERSION 3.19...3.22)

project(OpenGLCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

set(CONFIG_FILE_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(ModuleName "OpenGLCore")

set(export_config_file_path ${CMAKE_CURRENT_SOURCE_DIR}/Cmake/Export.h.in)
include(cmake/ExportFunction.cmake)
include(cmake/files_group.cmake)
include(cmake/resource_copy.cmake)
# for spdlog print debug info
set(ENABLE_DEBUG OFF)

if (ENABLE_DEBUG)
    add_definitions(-DSPDLOG_ACTIVE_LEVEL=1)
endif()

if(enable_testing)
    enable_testing()
    add_subdirectory(Testing)
endif()


add_subdirectory(Context)
add_subdirectory(Object)


