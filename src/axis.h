#ifndef _AXIS_H_
#define _AXIS_H_

struct Pix
{
    int x, y;
};

struct Cordinate
{
    double x, y;
};

class axis
{
private:
    int winWidth, winHeight;
    Cordinate center;
    double diam;

public:
    axis();
    axis(const Cordinate &, const double &);
    axis(const int &, const int &, const Cordinate &, const double &);
    int getWinWidth() const;
    int getWinHeight() const;
    Cordinate pix2cord(const Pix &p) const;
    Pix cord2pix(const Cordinate &c) const;
};

#endif