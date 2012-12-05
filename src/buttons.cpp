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

#include "buttons.h"

// NonInteractivePinButton Constructor
NonInteractivePinButton::NonInteractivePinButton( const QString& text, Qt::GlobalColor color, QWidget* parent ) :
				QPushButton( text, parent ) {
	
	QPalette palette( color );
	setPalette( palette );

	setEnabled( false );
}

// GroundPinButton Constructor
GroundPinButton::GroundPinButton( QWidget* parent ) :
				NonInteractivePinButton( "Ground", Qt::black, parent ) {
}

// ThreeVThreePinButton Constructor
ThreeVThreePinButton::ThreeVThreePinButton( QWidget* parent ) :
				NonInteractivePinButton( "3v3", Qt::darkYellow, parent ) {
}

// FiveVoltPinButton Constructor
FiveVoltPinButton::FiveVoltPinButton( QWidget* parent ) :
				NonInteractivePinButton( "5V", Qt::red, parent ) {
}

// IOPin Constructor
IOPin::IOPin( int address, QWidget* parent ) :
				QPushButton( parent ),
				_address(address) {
	
	char text[256];
	sprintf( text, "GPIO %d", _address );
	setText( text );
}

// mousePressEvent
void IOPin::mousePressEvent( QMouseEvent* event ) {

	printf( "TODO: Toggle pin %d here!\n", _address );
}
