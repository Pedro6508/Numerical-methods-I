cmake_minimum_required(VERSION 3.22)
project(Metodos_Numericos)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCE_FILES
        src/function.cpp
        src/main.cpp
        src/sonic_airplane.cpp
        src/output.cpp
)

# Include directories
include_directories(src)

# Add an executable target
add_executable(Executable ${SOURCE_FILES})

# Specify the output directory for the binary
set_target_properties(Executable PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)