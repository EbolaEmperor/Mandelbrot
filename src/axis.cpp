#include "axis.h"
#include <iostream>

axis::axis()
{
    winWidth = 1920;
    winHeight = 1080;
    diam = 5.0;
}

axis::axis(const Cordinate &c, const MPFloat &d)
{
    winWidth = 1920;
    winHeight = 1080;
    center = c;
    diam = d;
}

axis::axis(const int &w, const int &h, const Cordinate &c, const MPFloat &d)
{
    winWidth = w;
    winHeight = h;
    center = c;
    diam = d;
}

Pix axis::cord2pix(const Cordinate &c) const
{
    Pix centerPix = (Pix){winHeight/2, winWidth/2};
    Pix result;
    int maxLength = std::max(winHeight, winWidth);
    result.y = to_int((c.x - center.x) / diam * maxLength) + centerPix.y;
    result.x = centerPix.x - to_int((c.y - center.y) / diam * maxLength);
    return result;
}

Cordinate axis::pix2cord(const Pix &p) const
{
    Pix centerPix = (Pix){winHeight/2, winWidth/2};
    Cordinate result;
    MPFloat maxLength(std::max(winHeight, winWidth));
    result.x = MPFloat(p.y-centerPix.y) / maxLength * diam + center.x;
    result.y = MPFloat(centerPix.x-p.x) / maxLength * diam + center.y;
    return result;
}

int axis::getWinWidth() const
{
    return winWidth;
}

int axis::getWinHeight() const
{
    return winHeight;
}