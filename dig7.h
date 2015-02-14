#ifndef _DIG7_h_
#define _DIG7_h_

#include <Arduino.h>

/**
7-segment arduino library by AsGreyWolf
TODO: reverse support (+5v GND)
**/

class dig7{
	public:
		dig7(int top,int leftTop,int leftBottom,int bottom,int rightBottom,int rightTop,int middle,int point);
		void setup();
		void render();
		void push(unsigned char data);
		void pushInt(int num);
		void pushPoint(bool p);
	private:
		int pinsDig[8];
		unsigned char data;
};

#endif
