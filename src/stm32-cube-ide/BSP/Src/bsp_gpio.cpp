/*
 * gpio.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: charlesdias
 */
#include "board.h"
#include "main.h"
#include <assert.h>
#include "stm32f4xx_hal.h"

#define NUM_OF_ELEMS(a)    (sizeof(a) / sizeof(*(a)))

typedef struct
{
   GPIO_TypeDef* GPIO_Port;
   uint16_t      GPIO_Pin;
}GpioPins_t;

static GpioPins_t gpioPins[Board::Gpio::GPIO_NAME_LAST_ELEMENT] = {};

const GpioPins_t ledGreen = {.GPIO_Port = LD1_GPIO_Port, .GPIO_Pin = LD1_Pin};
const GpioPins_t ledBlue  = {.GPIO_Port = LD2_GPIO_Port, .GPIO_Pin = LD2_Pin};
const GpioPins_t ledRed   = {.GPIO_Port = LD3_GPIO_Port, .GPIO_Pin = LD3_Pin};

__attribute__((constructor))
void InitializeGpio(void)
{
   gpioPins[Board::Gpio::LED_GREEN] = ledGreen;
   gpioPins[Board::Gpio::LED_BLUE] = ledBlue;
   gpioPins[Board::Gpio::LED_RED] = ledRed;

   for(uint32_t i = 0; i < NUM_OF_ELEMS(gpioPins); ++i)
   {
      assert(gpioPins[i].GPIO_Port != NULL);
      assert(gpioPins[i].GPIO_Pin != 0);
   }
}

bool Board::Gpio::Read(Board::Gpio::PinName pinName)
{
   GpioPins_t gpio = gpioPins[pinName];
   assert(gpio.GPIO_Port != NULL);
   return HAL_GPIO_ReadPin((GPIO_TypeDef*)gpio.GPIO_Port, gpio.GPIO_Pin);
}

void Board::Gpio::Write(Board::Gpio::PinName pinName, bool value)
{
   GpioPins_t gpio = gpioPins[pinName];
   assert(gpio.GPIO_Port != NULL);
   HAL_GPIO_WritePin(gpio.GPIO_Port, gpio.GPIO_Pin, (GPIO_PinState)value);
}

void Board::Gpio::Toggle(Board::Gpio::PinName pinName)
{
   GpioPins_t gpio = gpioPins[pinName];
   assert(gpio.GPIO_Port != NULL);
   HAL_GPIO_TogglePin(gpio.GPIO_Port, gpio.GPIO_Pin);
}
