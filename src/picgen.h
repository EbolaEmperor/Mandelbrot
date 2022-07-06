#ifndef _PICGEN_H_
#define _PICGEN_H_

#include <complex>

void mandelbrotGen(std::complex<double> (*fun)(const std::complex<double> &, const std::complex<double> &), const double maxConvergeRadio, const char *Fname, 
                   const double centerX, const double centerY, const double diam, const int N, const int winWidth, const int winHeight);

void juliaGen(std::complex<double> (*fun)(const std::complex<double> &, const std::complex<double> &), const double maxConvergeRadio, const char *Fname, 
                   const double constX, const double constY, const double centerX, const double centerY, const double diam, const int N, const int winWidth, const int winHeight);


#endif