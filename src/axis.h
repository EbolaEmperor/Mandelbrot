#ifndef _AXIS_H_
#define _AXIS_H_

#include "GMP_Wrapper.h"

struct Pix{
    int x, y;
};

class Cordinate{
public:
    MPFloat x, y;
    Cordinate(): x(0), y(0) {}
    Cordinate(const MPFloat &x, const MPFloat &y): x(x), y(y) {}
    Cordinate(const Cordinate& rhs): x(rhs.x), y(rhs.y) {}
    Cordinate& operator = (const Cordinate& rhs){
        x = rhs.x; y = rhs.y;
        return *this;
    }
};

class axis
{
private:
    int winWidth, winHeight;
    Cordinate center;
    MPFloat diam;

public:
    axis();
    axis(const Cordinate &, const MPFloat &);
    axis(const int &, const int &, const Cordinate &, const MPFloat &);
    int getWinWidth() const;
    int getWinHeight() const;
    Cordinate pix2cord(const Pix &p) const;
    Pix cord2pix(const Cordinate &c) const;
};

#endif