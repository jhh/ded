cmake_minimum_required(VERSION 3.10)
project(Deadeye VERSION 0.1 LANGUAGES CXX)

# Project-wide setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(deadeye/daemon)

# Build main target
add_executable(ded
    main.cpp
)
set_target_properties(ded PROPERTIES
  OUTPUT_NAME ded
  EXPORT_NAME ded
)

target_link_libraries(ded
    PRIVATE
    Deadeye::library
)

