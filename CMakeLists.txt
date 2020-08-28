# --[ Project ] ---------------------------------------------------------------
cmake_minimum_required(VERSION 3.16)
project(logger LANGUAGES CXX)
# set(CMAKE_VERBOSE_MAKEFILE ON)

# --[ Library ] ---------------------------------------------------------------
add_library(${PROJECT_NAME} INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src)

# --[ Flags, Options, Defines ] -----------------------------------------------
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
# target_compile_options(${PROJECT_NAME} PRIVATE -Wno-unused-parameter)
# target_compile_options(${PROJECT_NAME} PRIVATE -Wno-unused-variable)
# target_compile_definitions(${PROJECT_NAME} PRIVATE MY_DEFINE)

# --[ Testing ] ---------------------------------------------------------------
set(TEST_NAME test)
add_executable(${TEST_NAME} src/test.cpp)
# set_target_properties(${TEST_NAME} PROPERTIES OUTPUT_NAME other_name)
target_compile_options(${TEST_NAME} PRIVATE -Wall -Wextra -Werror)
target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src)
if(WIN32 AND CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_link_options(${TEST_NAME} PRIVATE -static-libgcc -Wl,-static,-lpthread)
endif()

## ctest --build-and-test .. . --build-generator "Unix Makefiles" --test-command main_test
# enable_testing()
# add_test(TEST main_test)
