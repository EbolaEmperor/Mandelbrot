#include <stdlib.h>
#include <cstdio>

int main(int argc, char* argv[])
{
    //double x = -0.72624685;
    //double y = 0.240377;
    double d = 5.0;
    int n = 250;
    char syscmd[80];

    double x = std::atof(argv[1]);
    double y = std::atof(argv[2]);
    int branch = std::atoi(argv[3]);  //此参数用于多线程处理

    system("mkdir img");

    for(int i = 0; i < 3000; i++)
    {
        sprintf(syscmd, "./test img/pic%d.png %.8lf %.8lf %.15lf %d", i, x, y, d, n);
        if(i%4==branch)  //branch的用途见此处
        {
            printf("%s\n", syscmd);
            system(syscmd);
        }
        d *= 0.99;
        n *= 1.002313162;
    }

    return 0;
}
