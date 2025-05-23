cmake_minimum_required(VERSION 4.00)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_BINARY_DIR app)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/static)

#set lib
set(WLIB_STAT include/stat.h lib/stat.cpp)
set(WLIB_OUTPUT include/output.h lib/output.cpp)
set(WLIB_PORC include/proc.h lib/proc.cpp)

#set main
set(SRC src/main.cpp)

#project
project(onerow LANGUAGES CXX)

add_library(stat STATIC ${WLIB_STAT})
add_library(output STATIC ${WLIB_OUTPUT})
add_library(proc STATIC ${WLIB_PORC})

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

target_link_libraries(${CMAKE_PROJECT_NAME} proc)
target_link_libraries(${CMAKE_PROJECT_NAME} output)
target_link_libraries(${CMAKE_PROJECT_NAME} stat)

