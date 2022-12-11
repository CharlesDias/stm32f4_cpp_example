/*
 * board.h
 *
 *  Created on: Dec 11, 2022
 *      Author: charlesdias
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_

namespace Board
{
   namespace Gpio
   {
      enum PinName
      {
         LED_GREEN,
         LED_BLUE,
         LED_RED,
         GPIO_NAME_LAST_ELEMENT
      };

      bool Read(PinName pinName);
      void Write(PinName pinName, bool value);
      void Toggle(PinName pinName);
   }
}

#endif /* INC_BOARD_H_ */
