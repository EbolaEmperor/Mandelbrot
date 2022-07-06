#include "color.h"

RGB colorFunc1(const int &n)
{
    return (RGB)
    {
        (unsigned char)(255*log2(n)),
        (unsigned char)(155*log2(n)),
        150
    };
}

RGB colorFunc2(const int &n)
{
    return (RGB)
    {
        150,
        (unsigned char)(175*log2(n)),
        (unsigned char)(155*log2(n)),
    };
}

RGB colorFunc3(const int &n)
{
    return (RGB)
    {
        (unsigned char)((unsigned)(155*log2(n))%180u),
        100,
        (unsigned char)(255*log2(n)),
    };
}

RGB colorFuncContinous(const int &n)
{
    unsigned long long r = (unsigned long long)(255*log2(n))%512u;
    if(r >= 256u) r = 512u-r;
    return (RGB)
    {
        (unsigned char) r,
        (unsigned char)(155*log2(n)),
        150
    };
}

RGB colorFuncVango(const int &n)
{
    static const RGB vansColor[5] =
    {
        (RGB){26, 43, 96},
        (RGB){72, 88, 155},
        (RGB){132, 155, 182},
        (RGB){199, 179, 69},
        (RGB){201, 204, 135}
    };
    return vansColor[(unsigned char)(155*log2(n))%5];
}