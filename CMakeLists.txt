cmake_minimum_required(VERSION 3.15)

project("GraphExe" CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(src)
add_subdirectory(third_party/gtest)
add_subdirectory(Tests)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ViewLibrary)


find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    file(GLOB_RECURSE PROJECT_SOURCE_FILES
            ${CMAKE_SOURCE_DIR}/*.cpp
    )
    message(STATUS "clang-format found: ${CLANG_FORMAT}")
    add_custom_target(
            format
            COMMAND ${CLANG_FORMAT} -i -style=file ${PROJECT_SOURCE_FILES}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running clang-format"
    )
else()
    message(WARNING "clang-format not found. The format target will not be available.")
endif()