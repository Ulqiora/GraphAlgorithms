cmake_minimum_required(VERSION 3.15)

project("TestGraph" CXX)

add_subdirectory(ConfigureFilesCmake)

set(ConfigureTestsFile ${CMAKE_CURRENT_SOURCE_DIR}/ConfigureFilesCmake/config.h)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main_test.cpp ${ConfigureTestsFile})
target_link_libraries(${PROJECT_NAME} PUBLIC "GraphLib" gtest)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ConfigureFilesCmake)