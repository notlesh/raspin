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

#include <QtGui/QPushButton>

/**
 * Base class for non-interactive buttons.
 */
class NonInteractivePinButton : public QPushButton {

	public:

		/**
		 * Constructor. Takes a color, text string, and parent widget.
		 */
		NonInteractivePinButton( const QString& text, Qt::GlobalColor color, QWidget* parent );

		/**
		 * Virtual Destructor
		 */
		virtual ~NonInteractivePinButton() { };
};

/**
 * Ground pin. 
 */
class GroundPinButton : public NonInteractivePinButton {

	public:

		/**
		 * Constructor. Passes parent widget up the constructor chain. Uses black text "Ground"
		 */
		GroundPinButton( QWidget* parent );

		/**
		 * Virtual Destructor
		 */
		virtual ~GroundPinButton() { };
};

/**
 * 3v3 pin.
 */
class ThreeVThreePinButton : public NonInteractivePinButton {

	public:

		/**
		 * Constructor. Passes parent widget up the constructor chain. Uses red text "3v3"
		 */
		ThreeVThreePinButton( QWidget* parent );

		/**
		 * Virtual Destructor
		 */
		virtual ~ThreeVThreePinButton() { };
};

/**
 * 5v pin.
 */
class FiveVoltPinButton : public NonInteractivePinButton {

	public:

		/**
		 * Constructor. Passes parent widget up the constructor chain. Uses red text "5V."
		 */
		FiveVoltPinButton( QWidget* parent );

		/**
		 * Virtual Destructor
		 */
		virtual ~FiveVoltPinButton() { };
};

/**
 * IOPin class.
 */
class IOPin : public QPushButton {

	public:

		/**
		 * Constructor. Requires pin address in SOC numbering.
		 *
		 * @see http://quick2wire.com/2012/05/safe-controlled-access-to-gpio-on-the-raspberry-pi/
		 * for a thorough explanation of pin addressing.
		 */
		IOPin( int address, QWidget* parent );

		/**
		 * Virtual Destructor
		 */
		virtual ~IOPin() { };

		/**
		 * Sets Address
		 *
		 * @param address is the new value for Address
		 */
		void setAddress( int address ) { _address = address; };
		
		/**
		 * Returns Address
		 *
		 * @return Address
		 */
		int getAddress() const { return _address; };

		/**
		 * Mouse press event handler
		 */
		void mousePressEvent( QMouseEvent* event );

		/**
		 * Reflect pin state (adjust color)
		 */
		void reflectPinState();

	private:

		int _address;

};
