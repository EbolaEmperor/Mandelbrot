#include "FunIter.h"
#include <iostream>

std::complex<double> defeatQuadric(const std::complex<double> &z, const std::complex<double> &c)
{
	return z*z+c;
}

FunIter::FunIter()
{
	iterFunc = defeatQuadric;
	maxConvergeRadio = 2.0;
	curPoint = std::complex<double>(0.0,0.0);
	iterConst = std::complex<double>(0.0,0.0);
	iterTimes = maxIterTimes = 0;
}

FunIter::FunIter(std::complex<double> (*iFunc)(const std::complex<double> &, const std::complex<double> &), const double &mcr,
                 const std::complex<double> &p, const std::complex<double> &c, const int &n)
{
	iterFunc = iFunc;
	maxConvergeRadio = mcr;
	curPoint = p;
	iterConst = c;
	maxIterTimes = n;
	iterTimes = 0;
}

FunIter::FunIter(std::complex<double> (*iFunc)(const std::complex<double> &, const std::complex<double> &), const double &mcr,
                 const double &pr, const double &pi, const double &cr, const double &ci, const int &n)
{
	iterFunc = iFunc;
	maxConvergeRadio = mcr;
	curPoint = std::complex<double>(pr,pi);
	iterConst = std::complex<double>(cr,ci);
	maxIterTimes = n;
	iterTimes = 0;
}

FunIter::~FunIter()
{
	iterTimes = maxIterTimes = 0;
}

bool FunIter::unconverged() const
{
	return std::abs(curPoint) > 10;
}

bool FunIter::reachedMaxTimes() const
{
	return iterTimes >= maxIterTimes;
}

int FunIter::getIterTimes() const
{
	return iterTimes;
}

std::complex<double> FunIter::getCurPoint() const
{
	return curPoint;
}

void FunIter::iterate()
{
	if(iterTimes >= maxIterTimes)
	{
		std::cerr << "Mandelbrot Error: Iteration times has already reach the max." << std::endl;
		return;
	}
	curPoint = iterFunc(curPoint, iterConst);
	iterTimes ++;
}
