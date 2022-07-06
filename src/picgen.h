#ifndef _PICGEN_H_
#define _PICGEN_H_

#include <complex>

void mandelbrotGen(std::complex<double> (*fun)(const std::complex<double> &, const std::complex<double> &), const double, const char *, 
                   const double, const double, const double, const int, const int, const int);

void juliaGen(std::complex<double> (*fun)(const std::complex<double> &, const std::complex<double> &), const double, const char *, 
                   const double, const double, const double, const double, const double, const int, const int, const int);


#endif