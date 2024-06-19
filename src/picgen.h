#ifndef _PICGEN_H_
#define _PICGEN_H_

#include "FunIter.h"


void mandelbrotGen(IterFunc fun, 
                   const double maxConvergeRadio = 2.0, 
                   const char *Fname = nullptr, 
                   const MPFloat centerX = MPFloat(0), 
                   const MPFloat centerY = MPFloat(0), 
                   const MPFloat diam = MPFloat(5), 
                   const int N = 100, 
                   const int winWidth = 1920, 
                   const int winHeight = 1080);


void juliaGen(IterFunc fun, 
              const double maxConvergeRadio = 2.0, 
              const char *Fname = nullptr, 
              const MPFloat constX = 0.0, 
              const MPFloat constY = 0.0, 
              const MPFloat centerX = 0.0, 
              const MPFloat centerY = 0.0, 
              const MPFloat diam = 5.0, 
              const int N = 100, 
              const int winWidth = 1920, 
              const int winHeight = 1080);


#endif