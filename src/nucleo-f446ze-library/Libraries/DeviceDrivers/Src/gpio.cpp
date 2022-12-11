/*
 * gpio.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: charlesdias
 */

#include "DeviceDrivers/Include/gpio.h"

using namespace GpioDriver;

Gpio::Gpio(const Board::Gpio::PinName pinName, const ActiveLevel_t activeLevel)
   : _pinName(pinName), _activeLevel(activeLevel)
{

}

State_t Gpio::ReadPin(void) const
{
   if(Board::Gpio::Read(this->_pinName))
   {
      return State_t::GPIO_STATE_SET;
   }
   else
   {
      return State_t::GPIO_STATE_RESET;
   }
}

void Gpio::WritePin(State_t value) const
{
   Board::Gpio::Write(this->_pinName, (bool)value);
}

void Gpio::TogglePin(void) const
{
   Board::Gpio::Toggle(this->_pinName);
}
