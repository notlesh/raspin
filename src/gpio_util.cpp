/*
 * Copyright (c) 2012 Stephen Shelton
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdexcept>

#include <wiringPi.h>

#include "gpio_util.h"

// #define WIRING_PI_USE_SYS // uncomment to use GPIO interface in /sys, doesn't require root. not working currently...

using std::runtime_error;

// initialize
void initializeGPIO() {

#ifdef WIRING_PI_USE_SYS
	int error = wiringPiSetupSys(); // uses gpio interface in /sys and doesn't require root
#else
	int error = wiringPiSetupGpio(); // requires root, also very fast.
#endif
	if ( error ) {
		printf( "Error initializing (wiringPiSetupSys()): %d\n", error );
	}
}

// exportPin
void exportPin( int address ) {

#ifdef WIRING_PI_USE_SYS
	char buffer[256];
	sprintf( buffer, "/usr/local/bin/gpio-admin export %d", address );
	int error = system( buffer );
	if ( error ) {
		throw runtime_error( "Failed to execute gpio-admin" );
	}
#endif

}

// unexportPin
void unexportPin( int address ) {

#ifdef WIRING_PI_USE_SYS
	char buffer[256];
	sprintf( buffer, "/usr/local/bin/gpio-admin unexport %d", address );
	int error = system( buffer );
	if ( error ) {
		throw runtime_error( "Failed to execute gpio-admin" );
	}
#endif

}

// setPinDirection
void setPinDirection( int address, bool direction, bool exportAutomatically ) {

	if ( exportAutomatically ) {
		exportPin( address );
	}

	pinMode( address, direction ? OUTPUT : INPUT );

	if ( exportAutomatically ) {
		unexportPin( address );
	}

}

// readPin
bool readPin( int address, bool exportAutomatically ) {

	if ( exportAutomatically ) {
		exportPin( address );
	}

	bool value = (bool)digitalRead( address );

	if ( exportAutomatically ) {
		unexportPin( address );
	}

	return value;
}

// setPin
void setPin( int address, bool value, bool setPinDirectionAutomatically, bool exportAutomatically ) {


	if ( exportAutomatically ) {
		exportPin( address );
	}

	if ( setPinDirectionAutomatically ) {
		setPinDirection( address, true, false );
	}

	digitalWrite( address, value ? 1 : 0 );

	if ( exportAutomatically ) {
		unexportPin( address );
	}


}
