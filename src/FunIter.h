#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include "GMP_Wrapper.h"

typedef MPComplex (*IterFunc)(const MPComplex &, const MPComplex &);

class FunIter
{
private:
    MPComplex curPoint, iterConst;
    int iterTimes, maxIterTimes;
    IterFunc iterFunc;
    double maxConvergeRadio;

public:
    FunIter();
    FunIter(IterFunc, 
            const double &, 
            const MPComplex &, 
            const MPComplex &, 
            const int &);
    FunIter(IterFunc, 
            const double &, 
            const MPFloat &, 
            const MPFloat &, 
            const MPFloat &, 
            const MPFloat &, 
            const int &);
    ~FunIter();
    bool unconverged() const;
    bool reachedMaxTimes() const;
    int getIterTimes() const;
    MPComplex getCurPoint() const;
    void iterate();
};

#endif