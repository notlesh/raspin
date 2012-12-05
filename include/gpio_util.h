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

#include <stdio.h>

/**
 * Export a pin. Should be called before reading or setting a pin (called automatically by readPin()
 * and setPin(), setPin(), and setPinDirection() if exportAutomatically == true).
 */
void exportPin( int address );

/**
 * Unexport a pin. Should be called when done reading or setting a pin. (called automatically by
 * readPin(), setPin(), and setPinDirection() if exportAutomatically == true).
 */
void unexportPin( int address );

/**
 * Set the direction of a pin. Out is 1 (true), in is 0 (false).
 */
void setPinDirection( int address, bool direction, bool exportAutomatically = true );

/**
 * This will read the pin at a given address and return the state of the pin.
 */
bool readPin( int address, bool exportAutomatically = true );

/**
 * This will set the state of the pin at a given address.
 */
void setPin( int address, bool value, bool setPinDirectionAutomatically = true, bool exportAutomatically = true );
