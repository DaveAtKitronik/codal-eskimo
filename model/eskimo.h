/*
The MIT License (MIT)

Copyright (c) 2017 Lancaster University.
Amended by Kitronik Ltd to support Eskimo range (c) 2018 Kitronik Ltd

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef ESKIMO_H
#define ESKIMO_H

#include "mbed.h"

#include "CodalConfig.h"
#include "CodalHeapAllocator.h"
#include "CodalDevice.h"
#include "ErrorNo.h"
#include "eskimo_timer.h"
#include "Matrix4.h"
#include "CodalCompat.h"
#include "CodalComponent.h"
#include "ManagedType.h"
#include "ManagedString.h"
#include "Event.h"
#include "NotifyEvents.h"

#include "Button.h"
#include "MultiButton.h"
#include "MbedPin.h"
#include "MbedI2C.h"
#include "MbedSPI.h"
//*#include "LIS3DH.h"
//*#include "LinearAnalogSensor.h"
//*#include "NonLinearAnalogSensor.h"
#include "TouchSensor.h"

#include "MbedSerial.h"
#include "eskimoIO.h"

#include "CodalFiber.h"
#include "MessageBus.h"

namespace codal
{
    /**
      * Class definition for an Eskimo device.
      *
      * Represents the device as a whole, and includes member variables that represent various device drivers
      * used to control aspects of the device.
      */
    class Eskimo : public CodalDevice, public CodalComponent
    {
        private:



        /**
          * A listener to perform actions as a result of Message Bus reflection.
          *
          * In some cases we want to perform lazy instantiation of components, such as
          * the compass and the accelerometer, where we only want to add them to the idle
          * fiber when someone has the intention of using these components.
          */
        void                        onListenerRegisteredEvent(Event evt);
        uint8_t                     status;

        public:

        MessageBus                  messageBus;
        EskimoTimer                 timer;
        //mbed::Serial                serial;
        EskimoIO                    io;
        Button                      buttonA;
        Button                      buttonB;
        MultiButton                 buttonAB;

        //mbed::I2C                   i2c;
        //mbed::SPI                   flashSPI;


        /**
          * Constructor.
          *
          * Create a representation of an eskimo device, which includes member variables
          * that represent various device drivers used to control aspects of the board.
          */
        Eskimo();

        void idleCallback();
    };

    /**
      * A listener to perform actions as a result of Message Bus reflection.
      *
      * In some cases we want to perform lazy instantiation of components, such as
      * the compass and the accelerometer, where we only want to add them to the idle
      * fiber when someone has the intention of using these components.
      */
    void onListenerRegisteredEvent(Event evt);
}

using namespace codal;

#endif
