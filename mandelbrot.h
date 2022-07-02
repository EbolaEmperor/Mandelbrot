#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

#include <complex>

class mandelbrot
{
private:
    std::complex<double> curPoint, iterConst;
    int iterTimes, maxIterTimes;

public:
    mandelbrot();
    mandelbrot(const std::complex<double> &, const std::complex<double> &, const int &);
    mandelbrot(const double &, const double &, const double &, const double &, const int &);
    ~mandelbrot();
    bool unconverged() const;
    bool reachedMaxTimes() const;
    int getIterTimes() const;
    std::complex<double> getCurPoint() const;
    void iterate();
};

#endif