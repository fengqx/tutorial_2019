#include "STC12C5A60S2.H"
#include "intrins.h"
#define I2CDelay() {_nop_();_nop_();_nop_();_nop_();}
sbit I2C_SCL=P1^6;
sbit I2C_SDA=P1^7;
void I2CStart(){
	I2C_SDA=1;
	I2C_SCL=1;
	I2CDelay();
	I2C_SDA=0;
	I2CDelay();
	I2C_SCL=0; 
}
void I2CStop(){
	I2C_SCL=0;
	I2C_SDA=0;
	I2CDelay();
	I2C_SCL=1;
	I2CDelay();
	I2C_SDA=1;
	I2CDelay();
}
bit I2CWrite(unsigned char dat){
	bit ack;
	unsigned char mask;
	for(mask=0x80;mask!=0;mask>>=1){
		if((mask&dat)==0) I2C_SDA=0;
		else I2C_SDA=1;
		I2CDelay();
		I2C_SCL=1;
		I2CDelay();
		I2C_SCL=0;
	}
	I2C_SDA=1;
	I2CDelay();
	I2C_SCL=1;
	ack=I2C_SDA;
	I2CDelay();
	I2C_SCL=0;
	
	return (~ack);
}