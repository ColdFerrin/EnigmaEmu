// implementing the reflector
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Rotor.h"

Rotor::Rotor()
{
    srand(time(0));
    type = rand() % 8 + 1;
}

Rotor::Rotor(int Type)
{
    type = Type;
}

void Rotor::setup(int Position)
{
    position = Position;
}

void Rotor::encryptForward(char input)
{
    LetterBeingProcessed = input;
    if (LetterBeingProcessed >= 97)
    {
        LetterBeingProcessed -= 32;
    }
    LetterBeingProcessed -= 65;

    LetterBeingProcessed += position;
    if (LetterBeingProcessed >= 26)
    {
        LetterBeingProcessed %= 26;
    }

    switch (type)
    {
    case 1:
        outputForward.value = rotor1[LetterBeingProcessed];
        if (position == rotor1Turnover[0] || position == rotor1Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 2:
        outputForward.value = rotor2[LetterBeingProcessed];
        if (position == rotor2Turnover[0] || position == rotor2Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 3:
        outputForward.value = rotor3[LetterBeingProcessed];
        if (position == rotor3Turnover[0] || position == rotor3Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 4:
        outputForward.value = rotor4[LetterBeingProcessed];
        if (position == rotor4Turnover[0] || position == rotor4Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 5:
        outputForward.value = rotor5[LetterBeingProcessed];
        if (position == rotor5Turnover[0] || position == rotor5Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 6:
        outputForward.value = rotor6[LetterBeingProcessed];
        if (position == rotor6Turnover[0] || position == rotor6Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 7:
        outputForward.value = rotor7[LetterBeingProcessed];
        if (position == rotor7Turnover[0] || position == rotor7Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    case 8:
        outputForward.value = rotor8[LetterBeingProcessed];
        if (position == rotor8Turnover[0] || position == rotor8Turnover[1])
        {
            outputForward.moveNext = 1;
        }
        break;
    }
}

void Rotor::encryptReverse(char input, int rotate)
{

    switch (type)
    {
    case 1:
        for (int i = 0; i < 26; i++)
        {
            if (rotor1[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 2:
        for (int i = 0; i < 26; i++)
        {
            if (rotor2[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 3:
        for (int i = 0; i < 26; i++)
        {
            if (rotor3[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 4:
        for (int i = 0; i < 26; i++)
        {
            if (rotor4[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 5:
        for (int i = 0; i < 26; i++)
        {
            if (rotor5[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 6:
        for (int i = 0; i < 26; i++)
        {
            if (rotor6[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 7:
        for (int i = 0; i < 26; i++)
        {
            if (rotor7[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    case 8:
        for (int i = 0; i < 26; i++)
        {
            if (rotor8[i] == input)
            {
                char putback = i + 65 - position;
                if (putback < 65)
                {
                    putback += 26;
                }
                outputReverse.value = putback;
                break;
            }
        }
        break;
    }

    if (rotate)
    {
        position++;
    }

    if (position > 26)
    {
        position %= 26;
    }
}