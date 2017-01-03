// implementing the enigma machine
#include <iostream>
#include "EnigmaMachine.h"
using namespace std;

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
string EnigmaMachine::process(string input)
{
    char current;
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {

            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            {
                rightRotorInputForward = input[i];
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
                output += rotorRight.outputReverse.value;
            }
        }
    }
    return output;
}