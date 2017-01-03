#pragma once

#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include <string>
#include "Rotor.h"
#include "Reflector.h"

class EnigmaMachine {
private:
    Rotor rotorLeft;
    Rotor rotorMiddle;
    Rotor rotorRight;
    Reflector reflector;
    char rightRotorInputForward;
    char middleRotorInputForward;
    char leftRotorInputForward;
    char rightRotorInputReverse;
    char middleRotorInputReverse;
    char leftRotorInputReverse;
    char reflectorInput;
    char output;
    int leftRotorRotate;
    int middleRotorRotate;

public:

    EnigmaMachine();
    void build(Reflector ref, Rotor leftRotorType, Rotor middleRotorType, Rotor rightRotorType);
    void setup(int leftRotorPosittion, int middleRotorPosittion, int rightRotorPosittion);
    std::string process(std::string input);
};

#endif // !ENIGMAMACHINE_H_
