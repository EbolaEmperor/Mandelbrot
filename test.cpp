#include "picgen.h"
#include <mpi.h>

MPComplex fun(const MPComplex &z, const MPComplex &c){
    return z * z + c;
}

MPComplex fun2(const MPComplex &z, const MPComplex &c){
    return z*z*z*z + z*z*z / (z-1.0) + (z*z)/(z*z*z + z*z*4.0 + 5.0) + c;
}

int main(){
    MPI_Init(NULL, NULL);
    int maxIter = 200;
    MPFloat diam = 5.0Q;
    for(int i = 0; i < 260; ++i){
        char fname[30];
        sprintf(fname, "output/mandelbrot%d.png", i);
        mandelbrotGen(fun, 
                      2.0, 
                      fname, 
                      -0.726246869413187001644729Q,
                      0.2403769997069649677934455Q,
                      diam,
                      maxIter, 
                      1920, 
                      1080);
        maxIter *= 1.05;
        maxIter = std::min(maxIter, 3000000);
        diam *= 0.8;
        MPI_Barrier(MPI_COMM_WORLD);
    }
    MPI_Finalize();
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
