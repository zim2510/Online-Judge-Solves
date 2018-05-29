#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x;
    double n;
    while(scanf("%lf", &x)==1){
        scanf("%lf", &n);
        x = 1.0/x;
        printf("%0.0lf\n", pow(n, x));
    }
    return 0;
}
