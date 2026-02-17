cmake_minimum_required(VERSION 3.16)
project(systemy_wbudowane_zaliczenie_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build system info library
add_library(system_info_lib STATIC
    src/system_info.cpp
    src/diagnostics.cpp
)

target_include_directories(system_info_lib PUBLIC include)

# Build main executable
add_executable(zaliczenie2
    src/main.cpp
    src/diagnostics.cpp    
    src/student_output.cpp
)

target_include_directories(zaliczenie2 PRIVATE include)
target_link_libraries(zaliczenie2 PRIVATE system_info_lib)

# Compiler options
if(MSVC)
    target_compile_options(system_info_lib PRIVATE /W4)
    target_compile_options(zaliczenie2 PRIVATE /W4)
else()
    target_compile_options(system_info_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(zaliczenie2 PRIVATE -Wall -Wextra -Wpedantic)
endif()
