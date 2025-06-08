cmake_minimum_required(VERSION 3.10)
project(MainApp C)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the main executable
add_executable(main main.c)