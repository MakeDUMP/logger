# -----------------------------------------------------------------------------
# Project
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.19)
project(logger)

set(PROJECT_COMPILE_FEATURES cxx_std_17)
set(PROJECT_COMPILE_OPTIONS -Wall)
if(CMAKE_CXX_COMPILER_ID MATCHES "^(Clang|GNU)$")
    set(PROJECT_COMPILE_OPTIONS -Wno-unused-parameter -Wno-unused-variable)
endif()
#set(PROJECT_COMPILE_OPTIONS ${PROJECT_COMPILE_OPTIONS} -Wno-c++98-compat -Wno-c++98-compat-pedantic)
#set(PROJECT_COMPILE_OPTIONS ${PROJECT_COMPILE_OPTIONS} -Wno-global-constructors -Wno-exit-time-destructors -Wno-format-nonliteral -Wno-return-std-move)
set(PROJECT_COMPILE_DEFINES)
set(PROJECT_LINK_LIBRARIES)

set(PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_INCLUDES)
# set(PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

# -----------------------------------------------------------------------------
# Make Header-Only Library
# -----------------------------------------------------------------------------
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_INCLUDE_DIRS})

target_compile_features(${PROJECT_NAME} INTERFACE ${PROJECT_COMPILE_FEATURES})
target_compile_definitions(${PROJECT_NAME} INTERFACE ${PROJECT_COMPILE_DEFINES})
target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_COMPILE_OPTIONS})
