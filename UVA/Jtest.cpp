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
    double p, q, r, s, t, u, out;
    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u)==6){
        double lo = 0, hi = 1, x;
        for(int i = 0; i<50; i++){
            x = (lo+hi)/2;
            out = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
            if(out<0) hi = x;
            else lo = x;
        }
        double d;
        if(out>0) d = out;
        else d = -(out);
        if(d>0.0001) printf("No solution\n");
        else printf("%0.4lf\n", x);
    }
    return 0;
}