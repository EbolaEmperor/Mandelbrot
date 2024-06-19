#include "FunIter.h"
#include <iostream>

MPComplex defeatQuadric(const MPComplex &z, const MPComplex &c){
	return z * z + c;
}

FunIter::FunIter(){
	iterFunc = defeatQuadric;
	maxConvergeRadio = 2.0;
	iterTimes = maxIterTimes = 0;
}

FunIter::FunIter(IterFunc iFunc, 
				 const double &mcr,
                 const MPComplex &p,
				 const MPComplex &c,
				 const int &n) : curPoint(p), iterConst(c) {
	iterFunc = iFunc;
	maxConvergeRadio = mcr;
	maxIterTimes = n;
	iterTimes = 0;
}

FunIter::FunIter(IterFunc iFunc,
                 const double &mcr,
                 const MPFloat &pr,
				 const MPFloat &pi,
				 const MPFloat &cr,
				 const MPFloat &ci,
				 const int &n) : curPoint(pr, pi), iterConst(cr, ci){
	iterFunc = iFunc;
	maxConvergeRadio = mcr;
	maxIterTimes = n;
	iterTimes = 0;
}

FunIter::~FunIter(){
	iterTimes = maxIterTimes = 0;
}

bool FunIter::unconverged() const{
	return curPoint.cmpNorm(maxConvergeRadio) > 0;
}

bool FunIter::reachedMaxTimes() const{
	return iterTimes >= maxIterTimes;
}

int FunIter::getIterTimes() const{
	return iterTimes;
}

MPComplex FunIter::getCurPoint() const{
	return curPoint;
}

void FunIter::iterate(){
	if(iterTimes >= maxIterTimes){
		std::cerr << "Mandelbrot Error: Iteration times has already reach the max." << std::endl;
		return;
	}
	curPoint = iterFunc(curPoint, iterConst);
	iterTimes ++;
}
