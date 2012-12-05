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

#include "gpio_util.h"

using std::runtime_error;

// exportPin
void exportPin( int address ) {

	char buffer[256];
	sprintf( buffer, "/usr/local/bin/gpio-admin export %d", address );
	int error = system( buffer );
	if ( error ) {
		throw runtime_error( "Failed to execute gpio-admin" );
	}

}

// unexportPin
void unexportPin( int address ) {

	char buffer[256];
	sprintf( buffer, "/usr/local/bin/gpio-admin unexport %d", address );
	int error = system( buffer );
	if ( error ) {
		throw runtime_error( "Failed to execute gpio-admin" );
	}

}

// setPinDirection
void setPinDirection( int address, bool direction, bool exportAutomatically ) {

	if ( exportAutomatically ) {
		exportPin( address );
	}

	char buffer[256];
	if ( direction ) {
		sprintf( buffer, "echo out > /sys/devices/virtual/gpio/gpio%d/direction", address );
	} else {
		sprintf( buffer, "echo in > /sys/devices/virtual/gpio/gpio%d/direction", address );
	}

	FILE* stream = popen( buffer, "r" );
	if ( nullptr == stream ) {

		if ( exportAutomatically ) {
			unexportPin( address );
		}

		throw runtime_error( "Failed to set gpio pin direction" );
	}

	if ( exportAutomatically ) {
		unexportPin( address );
	}

}

// readPin
bool readPin( int address, bool exportAutomatically ) {

	if ( exportAutomatically ) {
		exportPin( address );
	}

	char buffer[256];
	sprintf( buffer, "cat /sys/devices/virtual/gpio/gpio%d/value", address );
	FILE* stream = popen( buffer, "r" );
	if ( nullptr == stream ) {

		if ( exportAutomatically ) {
			unexportPin( address );
		}

		throw runtime_error( "Failed to read gpio pin value" );
	}

	char c = fgetc( stream );
	fclose( stream );

	if ( exportAutomatically ) {
		unexportPin( address );
	}

	if ( c == '0' ) {
		return 0;
	} else if ( c == '1' ) {
		return 1;
	} else {
		throw runtime_error( "Failed to read gpio pin value (unrecognized value)" );
	}
}

// setPin
void setPin( int address, bool value, bool setPinDirectionAutomatically, bool exportAutomatically ) {

	if ( exportAutomatically ) {
		exportPin( address );
	}

	if ( setPinDirectionAutomatically ) {
		setPinDirection( address, true, false );
	}

	char buffer[256];
	if ( value ) {
		sprintf( buffer, "echo 1 > /sys/devices/virtual/gpio/gpio%d/value", address );
	} else {
		sprintf( buffer, "echo 0 > /sys/devices/virtual/gpio/gpio%d/value", address );
	}
	FILE* stream = popen( buffer, "r" );
	if ( nullptr == stream ) {

		if ( exportAutomatically ) {
			unexportPin( address );
		}

		throw runtime_error( "Failed to read gpio pin value" );
	}
	fclose( stream );

	if ( exportAutomatically ) {
		unexportPin( address );
	}


}
