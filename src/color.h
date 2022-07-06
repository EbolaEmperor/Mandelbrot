#ifndef _COLOR_H_
#define _COLOR_H_

#include <cmath>

struct RGB
{
    unsigned char r, g, b;
};

#define BLACK ((RGB){0,0,0})
#define WHITE ((RGB){255,255,255})
#define RED ((RGB){255,0,0})
#define GREEN ((RGB){0,255,0})
#define BLUE ((RGB){0,0,255})

RGB colorFunc1(const int &n);
RGB colorFunc2(const int &n);
RGB colorFunc3(const int &n);
RGB colorFuncContinous(const int &n);
RGB colorFuncVango(const int &n);

#endif