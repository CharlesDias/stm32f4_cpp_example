// #include "GpioMock.cpp"
// #include "main_override.h"
// #include "Drivers/Include/gpio.h"
// #include "hal_gpio_mock.cpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(GpioUnitTest, GPIO_Initialize_should_initialize_struct_field)
{
   // Expect to br true
   EXPECT_TRUE(1);

   // Expect to br false
   EXPECT_FALSE(0);
}