cmake_minimum_required(VERSION 3.21.0)

project(
   stm32f4_cpp_project
   VERSION 0.1.0
   DESCRIPTION "Development of a project model using the STM32F446ZE microcontroller programmed in C++."
   HOMEPAGE_URL https://github.com/CharlesDias/stm32f4_cpp_project
)

# Keep this options after project() command
enable_language(C ASM)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)               # Define explicitly to use of the standard C17 declared in the previous line
set(CMAKE_C_EXTENSIONS OFF)                     # Disabling vendor-specific extensions

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)             # Define explicitly to use of the standard C++17 declared in the previous line
set(CMAKE_CXX_EXTENSIONS OFF)                   # Disabling vendor-specific extensions

# If enabled, generates a compile_commands.json file containing the exact compiler calls for all 
# translation units of the project in machine-readable form.
# This is necessary for Sonarlint tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Select the right project to build
set(CHOOSE_TARGET_PLATFORM_BOARD board)
set(CHOOSE_TARGET_PLATFORM_TEST  test)

if (NOT (CHOOSE_TARGET_PLATFORM STREQUAL ${CHOOSE_TARGET_PLATFORM_BOARD} OR CHOOSE_TARGET_PLATFORM STREQUAL ${CHOOSE_TARGET_PLATFORM_TEST}))
   message(FATAL_ERROR
            "CHOOSE_TARGET_PLATFORM variable is not right.\n"
            "Pass the argument -DCHOOSE_TARGET_PLATFORM=Board or -DCHOOSE_TARGET_PLATFORM=Test.\n"
            "Example:\n cmake -DCHOOSE_TARGET_PLATFORM=Board -S . -B build/"
         )
endif()

# Variables name for target
set(LIBRARY_NAME library_gpio)
set(DRIVERS_LIBRARY_TARGET drivers_library)
set(MIDDLEWARE_LIBRARY_TARGET middleware_library)

# It must to be declare before the test folder
enable_testing()

if(CHOOSE_TARGET_PLATFORM STREQUAL ${CHOOSE_TARGET_PLATFORM_TEST})
   add_subdirectory(tests)
endif()

add_subdirectory(src)

# Print configuration status
message("\n========================================================")
message("Print configuration status.")
message(STATUS "Target platform .............. ${CHOOSE_TARGET_PLATFORM}")
message(STATUS "Generator .................... ${CMAKE_GENERATOR}")
message(STATUS "Build Type ................... ${CMAKE_BUILD_TYPE}")
message(STATUS "System name .................. ${CMAKE_SYSTEM_NAME}")
message(STATUS "System processor ............. ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Cross-compiling .............. ${CMAKE_CROSSCOMPILING}")
message(STATUS "C compiler ................... ${CMAKE_C_COMPILER}")
message(STATUS "C++ compiler ................. ${CMAKE_CXX_COMPILER}")
message("========================================================\n")
