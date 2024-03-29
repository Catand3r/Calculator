cmake_minimum_required(VERSION 3.10)
enable_testing()

project(
  Calculator
  VERSION 1.0
  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(FLAGS -Wall -Wextra -Werror -Wconversion -pedantic)


configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)


add_executable(${PROJECT_NAME} src/main.cpp src/Calculator.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

add_executable(${PROJECT_NAME}-ut tests/Calculator-ut.cpp src/Calculator.cpp)
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC gtest_main)

add_test(NAME CalculatorTests COMMAND ${PROJECT_NAME}-ut)