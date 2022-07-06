#include "picgen.h"
#include <complex>

using std::complex;
typedef complex<double> Complex;

Complex fun(const Complex &z, const Complex &c)
{
    return z*z*z*z + z*z*z/(z-1.0) + (z*z)/(z*z*z+4.0*z*z+5.0) + c;
}

int main()
{
    mandelbrotGen(fun, 2.0, "mandelbrot.png", 0.0, 0.0, 5.0, 200, 1920, 1080);
    double constX = -2.0;
    for(int i = 0; i <= 4000; i++)
    {
        char fname[30];
        sprintf(fname, "img/julia%d.png", i);
        juliaGen(fun, 2.0, fname, constX, 0.0, 0.0, 0.0, 5.0, 200, 1920, 1080);
        constX += 0.001;
    }
    return 0;
}