#include <stdio.h>

int main()
{
    int n;
    double v, t;
    scanf("%*d %d %lf", &n, &v);
    t = n*v;
    scanf("%*d %d %lf", &n, &v);
    t += n*v;
    printf("VALOR A PAGAR: R$ %0.2lf\n", t);
    return 0;
}
