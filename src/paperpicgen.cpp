#include <stdlib.h>
#include <cstdio>

int main()
{
    double x = -0.72624685;
    double y = 0.240377;
    double d = 5.0;
    int n = 100;
    char syscmd[80];

    for(int i = 0; i < 35; i++)
    {
        sprintf(syscmd, "./test img/pic%d.png %.8lf %.8lf %.12lf %d", i, x, y, d, n);
        printf("%s\n", syscmd);
        system(syscmd);
        d *= 0.5;
        if(i%3==1) n <<= 1;
    }

    return 0;
}
