#include <stdlib.h>
#include <cstdio>
#include <cmath>
#include "axis.h"

int main(int argc, char* argv[])
{
    //double x = -0.72624685;
    //double y = 0.240377;
    double d = 5.0;
    double n = 10000;
    char syscmd[160];

    double x = std::atof(argv[1]);
    double y = std::atof(argv[2]);
    int branch = std::atoi(argv[3]);  //此参数用于多线程处理

    axis myAxis((Cordinate){0,0}, d);
    Pix fixPix = myAxis.cord2pix((Cordinate){x,y});

    system("mkdir img");
    for(int i = 0; i < 1150; i++)
    {
        if(i%5==0)
        {
            if(fixPix.x > 540) fixPix.x--;
            if(fixPix.x < 540) fixPix.x++;
            if(fixPix.y > 960) fixPix.y--;
            if(fixPix.y < 960) fixPix.y++;
        }
        axis ithAxis((Cordinate){x,y}, d);
        Cordinate center = ithAxis.pix2cord((Pix){1080-fixPix.x, 1920-fixPix.y});
        sprintf(syscmd, "./picgen img/pic%d.png %.20lf %.20lf %.20lf %d", i, center.x, center.y, d, (int)round(n));
        if(i%4==branch)  //branch的用途见此处
        {
            printf("%s\n", syscmd);
            system(syscmd);
        }
        d *= 0.9895;
        d *= 0.9895;
    }

    return 0;
}
