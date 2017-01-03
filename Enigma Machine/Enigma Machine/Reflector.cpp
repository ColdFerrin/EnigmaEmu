// implementing the reflector
#include "Reflector.h"

Reflector::Reflector()
{
    type = 1;
}

Reflector::Reflector(int Type)
{
    type = Type;
}

char Reflector::process(char input)
{
    position = input;
    if (position > 97)
    {
        position -= 32;
    }
    position -= 65;

    switch (type)
    {
    case 1:
        return reflector1[position];
        break;
    case 2:
        return reflector2[position];
        break;
    case 3:
        return reflector3[position];
        break;
    }
}