//Program to emulate an enigma machine

#include <iostream>
//classes to include
#include "EnigmaMachine.h"
#include "Reflector.h"
#include "Rotor.h"
#include "Source.h"

using namespace std;

int main()
{
    //get user unput for rotor and reflector types
    int reflectorType, leftRotorType, middleRotorType, rightRotorType;
    cin >> reflectorType;
    cin >> leftRotorType;
    cin >> middleRotorType;
    cin >> rightRotorType;


    Reflector ref(reflectorType);
    Rotor rl(leftRotorType);
    Rotor rm(middleRotorType);
    Rotor rr(rightRotorType);
    EnigmaMachine enigmaMachine;
    enigmaMachine.build(ref, rl, rm, rr);

    int leftPosition, middlePosition, rightPosition;
    cin >> leftPosition;
    cin >> middlePosition;
    cin >> rightPosition;
    enigmaMachine.setup(leftPosition, middlePosition, rightPosition);

    string input;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, input);
    string output = "";
    int outputPos = 0;
    char encryptedChar;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            encryptedChar = enigmaMachine.process(input[i]);
            if (encryptedChar != 0)
            {
                output += encryptedChar;
            }
        }
    }
    //output[outputPos] = '/0';
    cout << output << endl;
    cin.get();
    return 0;
}