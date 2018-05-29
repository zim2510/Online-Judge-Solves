#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        double c, d, coef;
        scanf("%lf %lf %lf", &c, &d, &coef);
        double s = (1 + (d*coef))*c;
        printf("%lf\n", s);
        double lo = c/2, hi = 1000000, h;
        while(1)
        {
            double r = (hi+lo)/2;
            double t = 2 * asin(c/(2*r));
            double ts = r * t;
            if(ts == s|| lo==hi){
                h = r - r*cos(t/2);
                break;
            }
            else if(ts<s) hi = r;
            else lo = r;
        }
        if(s==c) printf("Case %d: %lf\n", i , 0);
        else printf("Case %d: %0.8lf\n", i, h);
    }
}
