#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        double ax, bx, ay, by, cx, dx, cy, dy, mndis = MAX;
        double x1, x2, y1, y2, x3, x4, y3, y4, dis1, dis2;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

        for(int i = 0; i<50; i++){

            x1 = (bx+2*ax)/3.0;
            y1 = (by+2*ay)/3.0;
            x2 = (ax+2*bx)/3.0;
            y2 = (ay+2*by)/3.0;
            x3 = (dx+2*cx)/3.0;
            y3 = (dy+2*cy)/3.0;
            x4 = (cx+2*dx)/3.0;
            y4 = (cy+2*dy)/3.0;

            dis1 = sqrt(SQR(x1-x3) + SQR(y1-y3));
            dis2 = sqrt(SQR(x2-x4) + SQR(y2-y4));


            if(dis1<=dis2){
                bx = x2;
                by = y2;
                dx = x4;
                dy = y4;
                if(dis1<mndis) mndis = dis1;
            }

            else{
                ax = x1;
                ay = y1;
                cx = x3;
                cy = y3;
                if(dis2<mndis) mndis = dis2;
            }

        }

        printf("Case %d: %0.8lf\n", i, mndis);

    }

    return 0;
}
