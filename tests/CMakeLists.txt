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