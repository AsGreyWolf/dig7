#include "dig7.h"
 unsigned char ints[]={
		0b11111100,
		0b00001100,
		0b10110110,
		0b10011110,
		0b01001110,
		0b11011010,
		0b11111010,
		0b10001100,
		0b11111110,
		0b11011110};
void dig7::setup(){
	for(int i=0;i<8;i++)
		pinMode(pinsDig[i],OUTPUT);
}
/*
               0
	          \/
	     ____________
	   /   ______    /
	1>/  /       /  /<5
	 /  /______ /  /
	/   ______    /
   /  /  /|   /  /
2>/  /___6__ /  /<4 _
 /____________ /   |_|<7
       
       /|
       3
	   
	   0 - top
	   1 - leftTop
	   2 - leftBottom
	   3 - bottom
	   4 - rightBottom
	   5 - rightTop
	   6 - middle
	   7 - point
*/
dig7::dig7(int top,int leftTop,int leftBottom,int bottom,int rightBottom,int rightTop,int middle,int point){
	pinsDig[0]=top;
	pinsDig[1]=leftTop;
	pinsDig[2]=leftBottom;
	pinsDig[3]=bottom;
	pinsDig[4]=rightBottom;
	pinsDig[5]=rightTop;
	pinsDig[6]=middle;
	pinsDig[7]=point;
	data=0xFF;
}
void dig7::render(){
	digitalWrite(pinsDig[0],(data>>7)&1);
	digitalWrite(pinsDig[1],(data>>6)&1);
	digitalWrite(pinsDig[2],(data>>5)&1);
	digitalWrite(pinsDig[3],(data>>4)&1);
	digitalWrite(pinsDig[4],(data>>3)&1);
	digitalWrite(pinsDig[5],(data>>2)&1);
	digitalWrite(pinsDig[6],(data>>1)&1);
	digitalWrite(pinsDig[7],(data>>0)&1);
}
void dig7::push(unsigned char data){
	this->data=data;
}
void dig7::pushInt(int num){
	push(ints[num%10]);
}
void dig7::pushPoint(bool p){
	if(p)
		data|=1;
	else
		data&=0;
}