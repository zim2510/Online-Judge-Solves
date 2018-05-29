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
    Read();
    Write();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        double x1, x2, x, y1, y2, y, z1, z2, z, dis1, dis2, mndis = MAX;
        double nx1, nx2, ny1, ny2, nz1, nz2;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x, &y, &z);
 
        for(int i = 0; i<200; i++){
 
            nx1 = (x2+2*x1)/3.0;
            ny1 = (y2+2*y1)/3.0;
            nz1 = (z2+2*z1)/3.0;

            nx2 = (x1+2*x2)/3.0;
            ny2 = (y1+2*y2)/3.0;
            nz2 = (z1+2*z2)/3.0;

            //double disi1 = sqrt(SQR(x1-x) + SQR(y1-y) + SQR(z1-z));
            //double disi2 = sqrt(SQR(x2-x) + SQR(y2-y) + SQR(z2-z));
 
            dis1 = sqrt(SQR(nx1-x) + SQR(ny1-y) + SQR(nz1-z));
            dis2 = sqrt(SQR(nx2-x) + SQR(ny2-y) + SQR(nz2-z));

 
            if(dis1>dis2){
                x1 = nx1;
                y1 = ny1;
                z1 = nz1;
            }
 
            else{
                x2 = nx2;
                x2 = nx2;
                z2 = nz2;
            }

        }
 
        printf("Case %d: %0.8f\n", i, (dis1+dis2)/2);
 
    }
 
    return 0;
}