#pragma once

#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{
private:
    int type;
    int position;
    char rotor1[28] = { 'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J' };
    char rotor1Turnover[2] = { 16,16 };
    char rotor2[28] = { 'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E' };
    char rotor2Turnover[2] = { 4,4 };
    char rotor3[28] = { 'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O' };
    char rotor3Turnover[2] = { 21,21 };
    char rotor4[28] = { 'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B' };
    char rotor4Turnover[2] = { 9,9 };
    char rotor5[28] = { 'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K' };
    char rotor5Turnover[2] = { 25,25 };
    char rotor6[28] = { 'J','P','G','V','O','U','M','F','Y','Q','B','E','N','H','Z','R','D','K','A','S','X','L','I','C','T','W' };
    char rotor6Turnover[2] = { 25,12 };
    char rotor7[28] = { 'N','Z','J','H','G','R','C','X','M','Y','S','W','B','O','U','F','A','I','V','L','P','E','K','Q','D','T' };
    char rotor7Turnover[2] = { 25,12 };
    char rotor8[28] = { 'F','K','Q','H','T','L','X','O','C','B','J','S','P','D','Z','R','A','M','E','W','N','I','U','Y','G','V' };
    char rotor8Turnover[2] = { 25,12 };
    char LetterBeingProcessed;
public:
    Rotor();
    Rotor(int Type);
    void setup(int Position);
    void encryptForward(char input);
    void encryptReverse(char input, int rotate);
    struct rotorOutput {
        char value;
        int moveNext = 0;
    }outputForward, outputReverse;
};

#endif // !ROTOR_H_