#pragma once

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector
{
private:
    int type;
    char reflector1[26] = { 'E','J','M','Z','A','L','Y','X','V','B','W','F','C','R','Q','U','O','N','T','S','P','I','K','H','G','D' };
    char reflector2[26] = { 'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T' };
    char reflector3[26] = { 'F','V','P','J','I','A','O','Y','E','D','R','Z','X','W','G','C','T','K','U','Q','S','B','N','M','H','L' };
    char position;
public:

    Reflector();
    Reflector(int Type);
    char process(char input);

};

#endif // !REFLECTOR_H