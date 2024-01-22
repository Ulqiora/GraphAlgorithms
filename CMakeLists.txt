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


