#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        double lr, wr;
        scanf("%lf : %lf", &lr, &wr);

        double lo = 0, hi = 400, ans;
        while(1){

            double mid = (lo+hi)/2;
            double l = mid*lr;
            double w = mid*wr;
            double r = sqrt(l*l+w*w)/2;
            double p = 200 - l;

            double t1 = acos((2*r*r - w*w)/(2*r*r));

            double p2 = r*t1;


            if(p-p2>=-0.000001 && p-p2<=0.000001){
                ans = mid;
                break;
            }
            else if(p>r*t1) lo = mid;
            else hi = mid;
        }
        printf("Case %d: %0.10lf %0.10lf\n", i, lr*ans, wr*ans);
    }
}
