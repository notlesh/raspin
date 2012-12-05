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

#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QMainWindow>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>

#include "buttons.h"

// main
int main( int argc, char *args[] ) {

	QApplication app( argc, args );

	QMainWindow* window = new QMainWindow();
	window->setWindowTitle( QString::fromUtf8( "Raspberry Pi Pin Controller" ));

	// main widget
	QWidget* mainWidget = new QWidget( window );
	QHBoxLayout* mainLayout = new QHBoxLayout( mainWidget );

	// left column
	QWidget* leftColumn = new QWidget( mainWidget );;
	QVBoxLayout* leftColumnLayout = new QVBoxLayout( leftColumn );

	QPushButton* pin1Button = new ThreeVThreePinButton( leftColumn );
	QPushButton* pin3Button = new QPushButton( "GPIO 0", leftColumn );
	QPushButton* pin5Button = new QPushButton( "GPIO 1", leftColumn );
	QPushButton* pin7Button = new QPushButton( "GPIO 4", leftColumn );
	QPushButton* pin9Button = new GroundPinButton( leftColumn );
	QPushButton* pin11Button = new QPushButton( "GPIO 17", leftColumn );
	QPushButton* pin13Button = new QPushButton( "GPIO 21", leftColumn );
	QPushButton* pin15Button = new QPushButton( "GPIO 22", leftColumn );
	QPushButton* pin17Button = new ThreeVThreePinButton( leftColumn );
	QPushButton* pin19Button = new QPushButton( "GPIO 10", leftColumn );
	QPushButton* pin21Button = new QPushButton( "GPIO 9", leftColumn );
	QPushButton* pin23Button = new QPushButton( "GPIO 11", leftColumn );
	QPushButton* pin25Button = new GroundPinButton( leftColumn );

	leftColumnLayout->addWidget( pin1Button );
	leftColumnLayout->addWidget( pin3Button );
	leftColumnLayout->addWidget( pin5Button );
	leftColumnLayout->addWidget( pin7Button );
	leftColumnLayout->addWidget( pin9Button );
	leftColumnLayout->addWidget( pin11Button );
	leftColumnLayout->addWidget( pin13Button );
	leftColumnLayout->addWidget( pin15Button );
	leftColumnLayout->addWidget( pin17Button );
	leftColumnLayout->addWidget( pin19Button );
	leftColumnLayout->addWidget( pin21Button );
	leftColumnLayout->addWidget( pin23Button );
	leftColumnLayout->addWidget( pin25Button );


	// right column
	QWidget* rightColumn = new QWidget( mainWidget );;
	QVBoxLayout* rightColumnLayout = new QVBoxLayout( rightColumn );

	QPushButton* pin2Button = new FiveVoltPinButton( rightColumn );
	QPushButton* pin4Button = new FiveVoltPinButton( rightColumn );
	QPushButton* pin6Button = new GroundPinButton( rightColumn );
	QPushButton* pin8Button = new QPushButton( "GPIO 14", rightColumn );
	QPushButton* pin10Button = new QPushButton( "GPIO 15", rightColumn );
	QPushButton* pin12Button = new QPushButton( "GPIO 18", rightColumn );
	QPushButton* pin14Button = new GroundPinButton( rightColumn );
	QPushButton* pin16Button = new QPushButton( "GPIO 23", rightColumn );
	QPushButton* pin18Button = new QPushButton( "GPIO 24", rightColumn );
	QPushButton* pin20Button = new GroundPinButton( rightColumn );
	QPushButton* pin22Button = new QPushButton( "GPIO 25", rightColumn );
	QPushButton* pin24Button = new QPushButton( "GPIO 8", rightColumn );
	QPushButton* pin26Button = new QPushButton( "GPIO 7", rightColumn );

	rightColumnLayout->addWidget( pin2Button );
	rightColumnLayout->addWidget( pin4Button );
	rightColumnLayout->addWidget( pin6Button );
	rightColumnLayout->addWidget( pin8Button );
	rightColumnLayout->addWidget( pin10Button );
	rightColumnLayout->addWidget( pin12Button );
	rightColumnLayout->addWidget( pin14Button );
	rightColumnLayout->addWidget( pin16Button );
	rightColumnLayout->addWidget( pin18Button );
	rightColumnLayout->addWidget( pin20Button );
	rightColumnLayout->addWidget( pin22Button );
	rightColumnLayout->addWidget( pin24Button );
	rightColumnLayout->addWidget( pin26Button );

	
	mainLayout->addWidget( leftColumn );
	mainLayout->addWidget( rightColumn );

	window->setCentralWidget( mainWidget );
	window->show();

	return app.exec();
}
