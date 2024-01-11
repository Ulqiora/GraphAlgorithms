cmake_minimum_required(VERSION 3.15)

project("TestGraph" CXX)

file(GLOB SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC "GraphLib" gtest)