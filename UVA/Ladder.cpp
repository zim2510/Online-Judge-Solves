#include <bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        double x, y, h;
        scanf("%lf %lf %lf", &x, &y, &h);
        double hi = min(x, y), lo = 0, mid, ans;
        int j = 0;
        while(1){
            mid = (hi+lo)/2;
            double t1 = acos(mid/x);
            double t2 = acos(mid/y);
            double t3 = pi/2 - t1;
            double t4 = pi/2 - t2;

            double h1 = x * sin(t1);
            double h2 = y * sin(t2);

            double area1 = (.5*mid*h1+ .5*mid*h2 - .5*mid* h);

            double n1 = .5*h2*(h/sin(t1)*sin(t3));
            double n2 = .5*h1*(h/sin(t2)*sin(t4));
            double area2 = (.5*mid*h + n1 + n2);

            double diff = area1 - area2;
            if(abs(diff)<=0.000001){
                ans = mid;
                break;
            }
            else if(diff<0) hi = mid;
            else if(diff>0) lo = mid;
        }

        printf("Case %d: %0.8lf\n", i, ans);;
    }
}

