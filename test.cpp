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
    mandelbrotGen(fun, 2.0, "test.png", 0.0, 0.0, 5.0, 200, 1920, 1080);
    return 0;
}