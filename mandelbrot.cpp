#include "mandelbrot.h"
#include <iostream>


mandelbrot::mandelbrot()
{
	iterTimes = maxIterTimes = 0;
}

mandelbrot::mandelbrot(const std::complex<double> &p, const std::complex<double> &c, const int &n)
{
	curPoint = p;
	iterConst = c;
	maxIterTimes = n;
	iterTimes = 0;
}

mandelbrot::mandelbrot(const double &pr, const double &pi, const double &cr, const double &ci, const int &n)
{
	curPoint = std::complex<double>(pr,pi);
	iterConst = std::complex<double>(cr,ci);
	maxIterTimes = n;
	iterTimes = 0;
}

mandelbrot::~mandelbrot()
{
	iterTimes = maxIterTimes = 0;
}

bool mandelbrot::unconverged() const
{
	return std::abs(curPoint) > 2;
}

bool mandelbrot::reachedMaxTimes() const
{
	return iterTimes >= maxIterTimes;
}

int mandelbrot::getIterTimes() const
{
	return iterTimes;
}

std::complex<double> mandelbrot::getCurPoint() const
{
	return curPoint;
}

void mandelbrot::iterate()
{
	if(iterTimes >= maxIterTimes)
	{
		std::cerr << "Mandelbrot Error: Iteration times has already reach the max." << std::endl;
		return;
	}
	curPoint = curPoint * curPoint + iterConst;
	iterTimes ++;
}
