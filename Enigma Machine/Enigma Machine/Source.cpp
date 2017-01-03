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
    cout << "This Program emulates the function of a WW2 German M3 Enigma Machine, as seen in the Imitation Game." << endl;

    cout << "There are three types of reflector type 1, type 2, and type 3." << endl;
    cout << "There are also 8 types of rotors #1 through #8 with diffrent wirings. The machine could take any" << endl << "combination of three diffrent rotors.";
    int restart;
    do
    {
        //get user unput for rotor and reflector types
        int reflectorType = 0, leftRotorType = 0, middleRotorType = 0, rightRotorType = 0;

        //Get an input for the reflector and make sure it is valid
        do
        {
            cout << endl << "Which reflector would you like to use: ";
            cin >> reflectorType;
            if (reflectorType > 3 || reflectorType < 1)
            {
                cout << endl << "You have entered an invalid reflector type";
            }

        } while (reflectorType > 3 || reflectorType < 1);

        //Get an input for the left rotor and make sure it is valid
        do
        {
            cout << endl << "Which rotor would you like to use in the left position: ";
            cin >> leftRotorType;
            if (leftRotorType > 8 || leftRotorType < 1)
            {
                cout << endl << "You have entered an invalid rotor type";
            }

        } while (leftRotorType > 8 || leftRotorType < 1);

        //Get an input for the middle rotor and make sure it is valid and not a duplicate
        do
        {
            cout << endl << "Which rotor would you like to use in the middle position: ";
            cin >> middleRotorType;
            if (middleRotorType > 8 || middleRotorType < 1)
            {
                cout << endl << "You have entered an invalid rotor type.";
            }
            else if (middleRotorType == leftRotorType)
            {
                cout << endl << "You may not use the same rotor type twice.";
            }

        } while ((middleRotorType > 8 || middleRotorType < 1) || middleRotorType == leftRotorType);

        //Get an input for the right rotor and make sure it is valid and not a duplicate
        do
        {
            cout << endl << "Which rotor would you like to use in the right position: ";
            cin >> rightRotorType;
            if (rightRotorType > 8 || rightRotorType < 1)
            {
                cout << endl << "You have entered an invalid rotor type.";
            }
            else if (rightRotorType == middleRotorType || rightRotorType == leftRotorType)
            {
                cout << endl << "You may not use the same rotor type twice.";
            }

        } while ((rightRotorType > 8 || rightRotorType < 1) || rightRotorType == middleRotorType || rightRotorType == leftRotorType);


        //create objects for the code to use
        Reflector ref(reflectorType);
        Rotor rl(leftRotorType);
        Rotor rm(middleRotorType);
        Rotor rr(rightRotorType);

        //create enigma machine and pass the objects to the enigma machine object
        EnigmaMachine enigmaMachine;
        enigmaMachine.build(ref, rl, rm, rr);

        //Ask for input for the rotor offset
        int leftPosition = 0, middlePosition = 0, rightPosition = 0;
        cout << endl << "Next you will set the offset/starting position for the rotors, which can be >= 1 and <= 26." << endl;
        //Get an input for the reflector and make sure it is valid
        do
        {
            cout << endl << "What offset would you like to use for the left rotor: ";
            cin >> leftPosition;
            if (leftPosition > 26 || leftPosition < 1)
            {
                cout << endl << "You have entered an invalid rotor position they must be >= 1 and <= 26";
            }

        } while (leftPosition > 26 || leftPosition < 1);

        do
        {
            cout << endl << "What offset would you like to use for the middle rotor: ";
            cin >> middlePosition;
            if (middlePosition > 26 || middlePosition < 1)
            {
                cout << endl << "You have entered an invalid rotor position they must be >= 1 and <= 26";
            }

        } while (middlePosition > 26 || middlePosition < 1);

        do
        {
            cout << endl << "What offset would you like to use for the right rotor: ";
            cin >> rightPosition;
            if (rightPosition > 26 || rightPosition < 1)
            {
                cout << endl << "You have entered an invalid rotor position they must be >= 1 and <= 26";
            }

        } while (rightPosition > 26 || rightPosition < 1);

        //pass the inputed values to the enigma machine
        enigmaMachine.setup(leftPosition, middlePosition, rightPosition);

        //get the input and process it
        cout << endl << "Enter your message or cyphertext. The program will ignore everything that is not a letter."
            << endl << "Take note of your settings or you will not be able to decypher your message." << endl;
        string input;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, input);
        string output = "";
        int outputPos = 0;
        char encryptedChar;
        output = enigmaMachine.process(input);
        
        cout << "Your message is:";
        cout << output << endl;

        char again;
        //ask to run again
        do
        {
            cout << "Would you like to run it again?(y/n)";
            cin >> again;

            if (again == 'y')
            {
                restart = 1;
            }
            else if (again == 'n')
            {
                restart = 0;
            }
        } while (again != 'y' && again != 'n');

    }while (restart == 1);

    cin.get();
    return 0;
}