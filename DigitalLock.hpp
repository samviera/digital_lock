#ifndef DIGITALLOCK_HPP
#define DIGITALLOCK_HPP
#include <array>

class DigitalLock{
public:
    DigitalLock();
    void inputChar(char input);

    private:
    enum State{
        Lock,S1,S2,S3,UNLOCK,W1,W2,W3,Alarm,
        A1,R1,R2,R3,Reset

    };

    State currentState;
    std::array<bool, 4>leds;//sim 4 led

    void transitionState(char input);
    void updateLEDs();
    void printLEDs();
    void reset();

};


#endif
