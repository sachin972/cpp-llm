
cmake_minimum_required(VERSION 3.20)

project(cpp_llm
    VERSION 0.1.0
    DESCRIPTION "A language model implemented from scratch in C++"
    LANGUAGES CXX
)

# Require modern C++ without compiler-specific extensions.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Keep generated executables in predictable locations
# for single- and multi-configuration generators.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

foreach(CONFIG DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
    set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG}
        "${CMAKE_BINARY_DIR}/bin/${CONFIG}"
    )
endforeach()

add_executable(cpp_llm
    src/main.cpp
)

target_include_directories(cpp_llm
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(MSVC)
    target_compile_options(cpp_llm PRIVATE /W4 /permissive-)
else()
    target_compile_options(cpp_llm PRIVATE -Wall -Wextra -Wpedantic)
endif()
