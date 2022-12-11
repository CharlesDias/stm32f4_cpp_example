/*
 * gpio.h
 *
 *  Created on: Dec 11, 2022
 *      Author: charlesdias
 */

#ifndef DEVICEDRIVERS_INCLUDE_GPIO_H_
#define DEVICEDRIVERS_INCLUDE_GPIO_H_
#include "board.h"
#include <cstdint>

namespace GpioDriver
{
   enum class State_t
   {
     GPIO_STATE_RESET = 0,
     GPIO_STATE_SET
   };

   enum class ActiveLevel_t
   {
      GPIO_ACTIVE_LOW,
      GPIO_ACTIVE_HIGH,
   };

   class Gpio
   {
      public:
         // Use convenient class-specific typedefs for increase portability.
         typedef std::uint32_t Gpio_t;

         Gpio(const Board::Gpio::PinName pinName, const ActiveLevel_t activeLevel);
         State_t ReadPin(void) const;
         void WritePin(State_t value) const;
         void TogglePin(void) const;

      private:
         Board::Gpio::PinName _pinName;
         ActiveLevel_t _activeLevel;
   };
}

#endif /* DEVICEDRIVERS_INCLUDE_GPIO_H_ */
