
cmake_minimum_required(VERSION 3.20)

project(cpp_llm
    VERSION 0.1.0
    DESCRIPTION "A language model implemented from scratch in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

foreach(CONFIG DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
    set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG}
        "${CMAKE_BINARY_DIR}/bin/${CONFIG}"
    )
endforeach()

# Reusable library for our core implementation.
add_library(llm_core
    src/diagnostics.cpp
)

target_include_directories(llm_core
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

function(enable_project_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(
            ${target} PRIVATE -Wall -Wextra -Wpedantic
        )
    endif()
endfunction()

enable_project_warnings(llm_core)

# Main application.
add_executable(cpp_llm
    src/main.cpp
)

target_link_libraries(cpp_llm PRIVATE llm_core)
enable_project_warnings(cpp_llm)

# Automated tests.
include(CTest)

if(BUILD_TESTING)
    add_executable(cpp_llm_tests
        tests/test_diagnostics.cpp
    )

    target_link_libraries(cpp_llm_tests PRIVATE llm_core)
    enable_project_warnings(cpp_llm_tests)

    add_test(
        NAME diagnostics_tests
        COMMAND cpp_llm_tests
    )
endif()
