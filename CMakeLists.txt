cmake_minimum_required(VERSION 3.15)

project("GraphExe" CXX)
set(CMAKE_CXX_STANDARD_DEFAULT 20)
add_subdirectory(src)
add_subdirectory(third_party/gtest)
add_subdirectory(Tests)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ViewLibrary)


