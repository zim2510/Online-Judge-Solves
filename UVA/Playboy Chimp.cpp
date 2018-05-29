#include <bits/stdc++.h>
//HERE PI MEANS 90 degrees, a mistake corrected by another :p
#define pi acos(0)
 
using namespace std;
double area(double hy, double th);
int main()
{
    freopen("in.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);
 
    for(int i = 1; i<=tc; i++){
        double x, y, h;
        scanf("%lf %lf %lf", &x, &y, &h);
        if(x<y) swap(x, y);
        double hi = y, lo = 0, mid;
        int j = 0;
        while(hi>=lo){
            mid = (hi+lo)/2;
 
            double t1 = acos(mid/x);
            double t2 = acos(mid/y);
            double t3 = pi - t1;
            double t4 = pi - t2;
 
            double h1 = x * sin(t1);
            double h2 = y * sin(t2);
 
            double area1 = (.5*mid*h1+ .5*mid*h2 - .5*mid* h);
 
            double n1 = .5*h2*(h/sin(t1)*sin(t3));
            double n2 = .5*h1*(h/sin(t2)*sin(t4));
            double area2 = (.5*mid*h + n1 + n2);
 			cout<<area1<<" "<<area2<<" "<<mid<<endl;
            double diff = area1 - area2;
            if(diff<=0.000001 && diff>=-0.000001){
                break;
            }
            else if(diff<0) hi = mid;
            else if(diff>0) lo = mid;
            //printf("%lf %lf %lf %lf %lf %lf %lf\n", t1, t2, t3, t4, h1, h2, area1, area2);
        }
 
        printf("Case %d: %lf\n", i, mid);;
    }
}