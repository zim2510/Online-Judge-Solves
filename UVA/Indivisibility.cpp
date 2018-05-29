#include <stdio.h>

int div[4] = {3, 19, 7};


long long f(long long x, long long i)
{
    long long int d = x/div[i];
    long long int m = 0;
    for(int s = 0; s<i; s++){
        m += f(d, s);
    }
    return d-m;
}

int main()
{
    long long int n, div, ndiv;
    scanf("%lld", &n);

    div = 0;
    for(int i = 0; i<3; i++){
        div += f(n, i);
    }

    ndiv = n - div;

    printf("%lld", n-ndiv);
    return 0;
}
