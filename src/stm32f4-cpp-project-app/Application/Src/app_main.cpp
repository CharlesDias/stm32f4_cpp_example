/*
 * app_main.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: charlesdias
 */

#include "DeviceDrivers/Include/gpio.h"
#include "../../Inc/app_main.h"

/* A unnamed namespace is called an anonymous namespace. An anonymous namespace limits
   the scope of anything within itself to file-level.*/
namespace
{
   // Create GPIO for LD1 (Green), LD1_GPIO_Port and LD1_Pin, GPIOB_BASE
   const GpioDriver::Gpio LedGreen
   {
      Board::Gpio::LED_GREEN,
      GpioDriver::ActiveLevel_t::GPIO_ACTIVE_HIGH
   };

//      const std::uint32_t GPIOB_BASE = reinterpret_cast<volatile std::uint32_t>GPIO_PIN_7;
//
//      // Create GPIO for LD2 (Blue), LD2_GPIO_Port and LD2_Pin
//      const GpioTemplate< std::uint32_t,
//                     std::uint16_t,
//                     PORT_LED_2,
//                     LD2_Pin > LedBlueTemplate;


// Create GPIO for LD3 (Red), LD3_GPIO_Port and LD3_Pin, GPIOB_BASE and GPIO_PIN_14

}

void app_main(void)
{
   while(1)
   {
      GpioDriver::State_t value = LedGreen.ReadPin();
      LedGreen.WritePin(GpioDriver::State_t::GPIO_STATE_RESET);
      LedGreen.WritePin(GpioDriver::State_t::GPIO_STATE_SET);
      LedGreen.TogglePin();
      LedGreen.TogglePin();
   }
}
