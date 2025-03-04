#include "DigitalLock.hpp"
#include <iostream>

int main(){
    DigitalLock lock;
    char input;
    std::cout<<"Enter characters(1,2,3, or any key):"<<std::endl;
    //superloop
    while(std::cin>>input){
        lock.inputChar(input);
    }
    return 0 ;
}
