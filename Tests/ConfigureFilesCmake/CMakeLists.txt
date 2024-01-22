cmake_minimum_required(VERSION 3.15)

set(PROJECT_PATH ${CMAKE_SOURCE_DIR})
message(STATUS "Project Path: ${PROJECT_PATH}")
message(STATUS "Generated configure file path: ${CMAKE_CURRENT_SOURCE_DIR}/config.h")
configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)