#include "png.h"
#include "axis.h"
#include "FunIter.h"
#include "color.h"
#include "picgen.h"
#include <cmath>
#include <cstring>

void mandelbrotGen(std::complex<double> (*fun)(const std::complex<double> &, const std::complex<double> &), const double maxConvergeRadio=2.0, const char *Fname=nullptr, 
                   const double centerX=0.0, const double centerY=0.0, const double diam=5.0, const int N=100, const int winWidth=1920, const int winHeight=1080)
{
    const char defeatFname[] = "test.png";
    const char *fname = Fname ? Fname : defeatFname;
    Cordinate center = (Cordinate){centerX, centerY};

    axis myAxis(winWidth, winHeight, center, diam);  //根据中心和直径定义一个像素点坐标-轴坐标转换器
    png myPng(myAxis.getWinHeight(), myAxis.getWinWidth());  //初始化一个png

    for(int i = 0; i < myAxis.getWinHeight(); i++)
        for(int j = 0; j < myAxis.getWinWidth(); j++)
        {
            Cordinate cord = myAxis.pix2cord((Pix){i,j});  //计算像素点(i,j)对应的轴坐标
            FunIter man(fun, maxConvergeRadio, 0.0, 0.0, cord.x, cord.y, N);   //给定迭代常数定义一个Mandelbrot迭代器
            while(!man.unconverged())  //进行迭代
            {
                man.iterate();
                if(man.reachedMaxTimes())
                    break;
            }
            if(man.unconverged())  //对不收敛区域进行着色
                myPng.setpix(i, j, colorFunc3(man.getIterTimes()));
            else
                myPng.setpix(i, j, BLACK);
        }
    
    myPng.output(fname);
}

void juliaGen(std::complex<double> (*fun)(const std::complex<double> &, const std::complex<double> &), const double maxConvergeRadio=2.0, const char *Fname=nullptr, 
                   const double constX=0.0, const double constY=0.0, const double centerX=0.0, const double centerY=0.0, const double diam=5.0, const int N=100, const int winWidth=1920, const int winHeight=1080)
{
    const char defeatFname[] = "test.png";
    const char *fname = Fname ? Fname : defeatFname;
    Cordinate center = (Cordinate){centerX, centerY};

    axis myAxis(winWidth, winHeight, center, diam);  //根据中心和直径定义一个像素点坐标-轴坐标转换器
    png myPng(myAxis.getWinHeight(), myAxis.getWinWidth());  //初始化一个png

    for(int i = 0; i < myAxis.getWinHeight(); i++)
        for(int j = 0; j < myAxis.getWinWidth(); j++)
        {
            Cordinate cord = myAxis.pix2cord((Pix){i,j});  //计算像素点(i,j)对应的轴坐标
            FunIter man(fun, maxConvergeRadio, cord.x, cord.y, constX, constY, N);   //给定迭代常数定义一个Mandelbrot迭代器
            while(!man.unconverged())  //进行迭代
            {
                man.iterate();
                if(man.reachedMaxTimes())
                    break;
            }
            if(man.unconverged())  //对不收敛区域进行着色
                myPng.setpix(i, j, colorFunc3(man.getIterTimes()));
            else
                myPng.setpix(i, j, BLACK);
        }
    
    myPng.output(fname);
}