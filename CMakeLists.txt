cmake_minimum_required(VERSION 3.31)
project(onerow VERSION 1.0.1 LANGUAGES CXX)

# -------------------------------------------------------------
# to switch packaging to *.tar.gz >>> set(assemble_tgz ON)
set(assemble_tgz OFF)
# -------------------------------------------------------------

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(onerow_wlib_stat SHARED ${CMAKE_SOURCE_DIR}/lib/stat.cpp)
target_include_directories(onerow_wlib_stat PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(onerow_wlib_output SHARED ${CMAKE_SOURCE_DIR}/lib/output.cpp)
target_include_directories(onerow_wlib_output PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(onerow_wlib_proc SHARED ${CMAKE_SOURCE_DIR}/lib/proc.cpp)
target_include_directories(onerow_wlib_proc PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC onerow_wlib_stat onerow_wlib_output onerow_wlib_proc)

# -------------------------------------------------------------
# packaging

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "One row statistics for Linux terminal")

if (assemble_tgz)
    install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
    install(TARGETS onerow_wlib_stat onerow_wlib_output onerow_wlib_proc LIBRARY DESTINATION lib)
    install(FILES ${CMAKE_SOURCE_DIR}/sources/onerow DESTINATION "." PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
    set(CPACK_GENERATOR "TGZ")
else ()
    include(GNUInstallDirs)
    install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    install(TARGETS onerow_wlib_stat onerow_wlib_output onerow_wlib_proc LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
    set(CPACK_GENERATOR "RPM")
    set(CPACK_RPM_PACKAGE_RELOCATABLE "TRUE")
endif ()

include(CPack)
