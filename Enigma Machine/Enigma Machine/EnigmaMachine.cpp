// implementing the enigma machine
#include <iostream>
#include "EnigmaMachine.h"

EnigmaMachine::EnigmaMachine()
{

}
void EnigmaMachine::build(Reflector ref, Rotor leftRotorType, Rotor middleRotorType, Rotor rightRotorType)
{
    rotorLeft = leftRotorType;
    rotorMiddle = middleRotorType;
    rotorRight = rightRotorType;
    reflector = ref;
}
void EnigmaMachine::setup(int leftRotorPosittion, int middleRotorPosittion, int rightRotorPosittion)
{
    rotorLeft.setup(leftRotorPosittion - 1);
    rotorMiddle.setup(middleRotorPosittion - 1);
    rotorRight.setup(rightRotorPosittion - 1);
}
char EnigmaMachine::process(char input)
{
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
    {
        rightRotorInputForward = input;
        rotorRight.encryptForward(rightRotorInputForward);

        middleRotorInputForward = rotorRight.outputForward.value;
        //std::cout << middleRotorInputForward;
        rotorMiddle.encryptForward(middleRotorInputForward);

        leftRotorInputForward = rotorMiddle.outputForward.value;
        //std::cout << leftRotorInputForward;
        rotorLeft.encryptForward(leftRotorInputForward);

        reflectorInput = rotorLeft.outputForward.value;
        //std::cout << reflectorInput;
        leftRotorInputReverse = reflector.process(reflectorInput);
        //std::cout << leftRotorInputReverse;

        rotorLeft.encryptReverse(leftRotorInputReverse, rotorMiddle.outputForward.moveNext);

        middleRotorInputReverse = rotorLeft.outputReverse.value;
        //std::cout << middleRotorInputReverse;
        rotorMiddle.encryptReverse(middleRotorInputReverse, rotorRight.outputForward.moveNext);

        rightRotorInputReverse = rotorMiddle.outputReverse.value;
        //std::cout << rightRotorInputReverse;
        rotorRight.encryptReverse(rightRotorInputReverse, 1);
        output = rotorRight.outputReverse.value;
        return output;
    }
    else
    {
        return 0;
    }

}