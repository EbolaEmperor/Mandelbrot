#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include <complex>

class FunIter
{
private:
    std::complex<double> curPoint, iterConst;
    int iterTimes, maxIterTimes;
    std::complex<double> (*iterFunc)(const std::complex<double> &, const std::complex<double> &);
    double maxConvergeRadio;

public:
    FunIter();
    FunIter(std::complex<double> (*iterFunc)(const std::complex<double> &, const std::complex<double> &), const double &, 
            const std::complex<double> &, const std::complex<double> &, const int &);
    FunIter(std::complex<double> (*iterFunc)(const std::complex<double> &, const std::complex<double> &), const double &, 
            const double &, const double &, const double &, const double &, const int &);
    ~FunIter();
    bool unconverged() const;
    bool reachedMaxTimes() const;
    int getIterTimes() const;
    std::complex<double> getCurPoint() const;
    void iterate();
};

#endif