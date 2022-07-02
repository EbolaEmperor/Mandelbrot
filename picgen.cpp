#include "png.h"
#include "axis.h"
#include "mandelbrot.h"
#include <cmath>

int main(int argc, char* argv[])
{
    const char defeatFname[] = "test.png";
    char *fname;
    Cordinate center = (Cordinate){0.0, 0.0};
    double diam = 5.0;
    int N = 100;

    if(argc >= 2) fname = argv[1];
    if(argc >= 4) center = (Cordinate){std::atof(argv[2]), std::atof(argv[3])};
    if(argc >= 5) diam = std::atof(argv[4]);
    if(argc >= 6) N = std::atoi(argv[5]);

    axis myAxis(center, diam);  //根据中心和直径定义一个像素点坐标-轴坐标转换器
    png myPng(myAxis.getWinHeight(), myAxis.getWinWidth());  //初始化一个png

    for(int i = 0; i < myAxis.getWinHeight(); i++)
        for(int j = 0; j < myAxis.getWinWidth(); j++)
        {
            Cordinate cord = myAxis.pix2cord((Pix){i,j});  //计算像素点(i,j)对应的轴坐标
            mandelbrot man(0.0, 0.0, cord.x, cord.y, N);   //给定迭代常数定义一个Mandelbrot迭代器
            while(!man.unconverged())  //进行迭代
            {
                man.iterate();
                if(man.reachedMaxTimes())
                    break;
            }
            if(man.unconverged())  //对不收敛区域进行着色
            {
                unsigned char red = (unsigned char)(255*log2(man.getIterTimes()));
                unsigned char green = (unsigned char)(155*log2(man.getIterTimes()));
                myPng.setpix(i, j, red, green, 150);
            }
            else
                myPng.setpix(i, j, 0, 0, 0);
        }
    
    myPng.output(fname);
    return 0;
}