#include "picgen.h"

MPComplex fun(const MPComplex &z, const MPComplex &c){
    return z * z + c;
}

MPComplex fun2(const MPComplex &z, const MPComplex &c){
    return z*z*z*z + z*z*z / (z-1.0) + (z*z)/(z*z*z + z*z*4.0 + 5.0) + c;
}

int main()
{
    mandelbrotGen(fun, 
                  2.0, 
                  "mandelbrot.png", 
                //   MPFloat("-0.726246869413187002"), 
                //    MPFloat("0.240376999706964972"), 
                //    MPFloat("0.00000000000000002"), 
                  -0.726246869413187002Q,
                   0.240376999706964968Q,
                   5.0Q,//0.00000000000000001Q,
                  200, 
                  1920, 
                  1080);
    /*
    double constX = -2.0;
    for(int i = 0; i <= 4000; i++)
    {
        char fname[30];
        sprintf(fname, "img/julia%d.png", i);
        juliaGen(fun, 2.0, fname, constX, 0.0, 0.0, 0.0, 5.0, 200, 1920, 1080);
        constX += 0.001;
    }
    */
    return 0;
}
