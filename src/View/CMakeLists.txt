cmake_minimum_required(VERSION 3.15)

project("ViewLibrary" CXX)
file(GLOB SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
file(GLOB HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC GraphLib)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
