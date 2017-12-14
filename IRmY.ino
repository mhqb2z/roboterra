/*
* IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
* An IR detector/demodulator must be connected to the input RECV_PIN.
* Version 0.1 July, 2009
* Copyright 2009 Ken Shirriff
* http://arcfn.com
*/

#include "IRremote.h"

int RECV_PIN = 11;
int duplicate = 0xFFFFFFFF;
int preValue = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}

void loop() {
	
	if (irrecv.decode(&results)) {
		//Serial.println(results.value, HEX);
		if (results.value != duplicate) {
			preValue = results.value;
		}		
		switch (preValue)
		{
		case 0x30CF:
			Serial.println("0");
			break;
		case 0xFD08F7:
			Serial.println("1");
			break;
		case 0xFD8877:
			Serial.println("2");
			break;
		case 0xFD48B7:
			Serial.println("3");
			break;
		case 0xFD28D7:
			Serial.println("4");
			break;
		case 0xFDA857:
			Serial.println("5");
			break;
		case 0xFD6897:
			Serial.println("6");
			break;
		case 0xFD18E7:
			Serial.println("7");
			break;
		case 0xFD9867:
			Serial.println("8");
			break;
		case 0xFD58A7:
			Serial.println("9");
			break;
		case 0xFD50AF:
			Serial.println("Up");
			break;
		case 0xFD10EF:
			Serial.println("Down");
			break;
		case 0x20DF:
			Serial.println("FastBack");
			break;
		case 0x609F:
			Serial.println("FastForward");
			break;
		case 0xFFFFA05F:
			Serial.println("Play");
			break;
		case 0xFFFF807F:
			Serial.println("VOL+");
			break;
		case 0x40BF:
			Serial.println("FUNC/STOP");
			break;
		case 0xFF:
			Serial.println("Shut");
			break;
		case 0xFFFFB04F:
			Serial.println("EQ");
			break;
		case 0x708F:
			Serial.println("ST/REPT");
			break;
		case 0xFFFF906F:
			Serial.println("VOL-");
			break;
		default:
			Serial.println(preValue, HEX);
			break;
		}
		irrecv.resume(); // Receive the next value
	}
}