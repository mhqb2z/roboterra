#include "ROBOTERRA.h"

/*--------------------- STEP 1 ---------------------*/

RoboTerraRoboCore control;

RoboTerraButton btn1;  
RoboTerraButton btn2;  
RoboTerraButton btn3;  
RoboTerraButton btn4;  
RoboTerraButton btn5;  
RoboTerraButton btn6;   
RoboTerraButton btn7;   
RoboTerraButton btn8;   

RoboTerraIRTransmitter trans;
RoboTerraJoystick joy;

int x = 0;
int y = 0;
int mergedata=0; 

int control_mode=0;  


 
bool startcontrol=true;
int doubleSpeed = 1;

/*--------------------- STEP 2 ---------------------*/

void attachRoboTerraElectronics() {
    
    control.attach(btn1,DIO_1);
    control.attach(btn2,DIO_2);   
    control.attach(btn3,DIO_3);
    control.attach(btn4,DIO_4);
    control.attach(btn5,DIO_5);   
    control.attach(btn6,DIO_6);
    control.attach(btn7,DIO_7);   
    control.attach(btn8,DIO_8);
    
     
    control.attach(trans,IR_TRAN);
    control.attach(joy,AI_1,AI_2);
    //AI1 for X; AI2 for Y;

}

/*--------------------- STEP 3 ---------------------*/


void SendIRsignal(){
 
 if   (startcontrol==true) {  
      mergedata=( x * doubleSpeed + 5 ) * 100 + ( y * doubleSpeed + 5 );
      
       
       
       

      trans.emit(mergedata,control_mode);
 }

}



void handleRoboTerraEvent() {
    if (EVENT.isType(ROBOCORE_LAUNCH)) {
        joy.activate();
     	trans.activate();
    }
    if(EVENT.isType(JOYSTICK_X_UPDATE)){

        x = EVENT.getData();
        control_mode=0;
        SendIRsignal();
       
    }
    if(EVENT.isType(JOYSTICK_Y_UPDATE)){
        control_mode=0;
        y = EVENT.getData();
        SendIRsignal();
     	
    }
    
    
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn1)){
        
       control_mode=1;
       SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn2)){
    
        control_mode=2;  //
        SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn3)){
       
        control_mode=3;  //
        SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn4)){
       
        control_mode=4;  //
        SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn5)){
       
        control_mode=5;  //
        SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn6)){
       
        control_mode=6;  //
        SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn7)){
       
        control_mode=7;  //
        SendIRsignal();
    }
    
    if(EVENT.isType(BUTTON_PRESS)&&EVENT.isFrom(btn8)){
       
        control_mode=8;  //
        SendIRsignal();
    }

}
