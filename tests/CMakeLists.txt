message(STATUS "EXTERNAL: Clone Google Test Framework from Git repository...")
include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest.git
   GIT_TAG v1.13.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

############################ Test Project ############################
set(TEST_FOLDER_PATH "${CMAKE_SOURCE_DIR}/tests")
set(GTEST_REPORT_FOLDER_PATH "${CMAKE_SOURCE_DIR}/build-artifacts/gtest_report/out")

######################################################################
# Unit tests for drivers functions
set(DRIVERS_UNIT_TEST DriversUnitTest)
add_executable( ${DRIVERS_UNIT_TEST}
   ${TEST_FOLDER_PATH}/unit/device-drivers/gpio_test.cpp
)

target_link_libraries( ${DRIVERS_UNIT_TEST} PUBLIC
   ${DRIVERS_LIBRARY_TARGET}
   GTest::gmock_main
)
gtest_discover_tests( ${DRIVERS_UNIT_TEST}
   XML_OUTPUT_DIR ${GTEST_REPORT_FOLDER_PATH}
)