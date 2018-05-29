#include <stdio.h>
int main()
{
    double a, b, c, d;
    a=1;
    b=0;
    c=1;
    d=0;
    while(d<100){
        c=b+a;
        printf("%0.00lf\n", c);
        a=b;
        b=c;

        d++;
    }
    return 0;
}
