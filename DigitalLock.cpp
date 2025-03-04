#include "DigitalLock.hpp"
#include <iostream>

DigitalLock::DigitalLock() :
    currentState(Lock),
    leds({false, false, false, false }){

//DOESNT DO ANYTHING AKA EMPTY BODY
    }

void DigitalLock::inputChar (char input){
    transitionState(input);//mem function
    updateLEDs();
    printLEDs();
    //reset();

}

void DigitalLock::transitionState(char input){
    //use member variale
    switch (currentState){
        case Lock:
        if (input == '2'){ //if input is 2 s1
            currentState = S1;
        } else if (input == '1'){ //if 1 go to R1
            currentState = R1;
        } else { //anything else W1
            currentState= W1;
    
        }
        break;


        case S1:
        if (input == '3'){
            currentState = S2;
        } else if (input=='1'){
            currentState = R2;     
    } else {
            currentState = W2;
    }
    break;


    case S2:
    if (input == '1'){
            currentState=S3;
        } else{
            currentState= W3;
        } 
        break;

    case S3:
    if (input == '3'){
            currentState=UNLOCK;
        } else if (input == '1'){
            currentState = Reset;
        } else {
            currentState = Alarm;
    
        }
        break;


        case UNLOCK:
            currentState = Reset;
        break;


        case W1:
        if (input == '1'){
            currentState = R2;
        } else {
            currentState = W2;
    
        }
        break;


        case W2:
        if (input == '1'){
            currentState=R3;
        } else {
            currentState= W3;
        }
        break;


         case W3:
            currentState= Alarm;
        
        break;


        case Alarm:
        if (input == '3'){
        currentState=A1;
        }
        break;

        case A1:
        if  (input=='1'){
        currentState = Reset;
        }else{
        currentState=Alarm;
        }
        break;


        case R1:
        if(input == '1'){
        currentState = Reset;
        }
        else{
        currentState=W2;
        }
    break;


      case R2:
        if(input == '1'){
        currentState = Reset;
        }
        
        else{
        currentState=W3;
        }
    break;


      case R3:
        if(input == '1'){
        currentState = Reset;
        }

        else{
        currentState=W2;
        }
        break;

        case Reset:
        currentState=Lock;
        break;
    }

}



void DigitalLock::updateLEDs(){
switch (currentState){
    case Lock:
    std::cout<< "Current Sate:Lock"<<std::endl;
    std::cout<< "*********************"<<std::endl;
    std::cout<< "Locked :)"<<std::endl;
    std::cout<< "*********************"<<std::endl;
    break;


    case S1:
    std::cout<<"Current State S1"<<std::endl;
    leds[0]=true;
    break;

    case S2:
    std::cout<<"Current State S2"<<std::endl;
    leds[1]=true;
    break;

    case S3:
    std::cout<<"Current State S3"<<std::endl;
    leds[2]=true;
    break;

    case W1:
    std::cout<<"Current State W1"<<std::endl;
    leds[0]=true;
    break;

    case W2:
    std::cout<<"Current State W2"<<std::endl;
    leds[1]=true;
    break;

    case W3:
    std::cout<<"Current State W3"<<std::endl;
    leds[2]=true;
    break;

    case R1:
    std::cout<<"Current State R1"<<std::endl;
    leds[0]=true;
    break;

    case R2:
    std::cout<<"Current State R2"<<std::endl;
    leds[1]=true;
    break;

    case R3:
    std::cout<<"Current State R2"<<std::endl;
    leds[2]=true;
    break;


    case Alarm:
    std::cout<<"ALARM FLASH FLASH FLASH"<<std::endl;
    break;


    case A1:
    std::cout<<"Current State A1"<<std::endl;
    std::cout<<"ALARM FLASH FLASH FLASH"<<std::endl;
    break;


    case UNLOCK:
    std::cout<< "Current Sate:UNLOCK"<<std::endl;
    std::cout<< "*********************"<<std::endl;
    std::cout<< "UNLOCKED :)"<<std::endl;
    std::cout<< "*********************"<<std::endl;
    break;

    case Reset:
    std::cout<< "Current State:Reset"<<std::endl;
    leds.fill(true);
    reset();
    break;
    default:
    break;



}


}
//void DigitalLock::reset() {
    // Implement the reset functionality here
   // currentState = Lock;
   // leds.fill(false);
//}



void DigitalLock::printLEDs(){
    std::cout<< "LEDs Status:";
    if(currentState==UNLOCK){
        for (bool led : leds){ ///GET EVERY OBJECT FROM LEDS AND PUT IN LED
            std::cout<< "[Flash]"; //WHEN UNLOCK D-FLASH LEDS

        }
    }else if (currentState == Alarm || currentState==A1 ){
        for (bool led:leds){
            std::cout<<"[Alarm]";
        } 
        } else {
            for (bool led:leds){
                std::cout<<(led?"[ON]" :"[OFF]");
            }
        }
        std::cout<<std::endl;
    }


    void DigitalLock::reset(){
        leds.fill(false); //get led array and fill with false
    }
