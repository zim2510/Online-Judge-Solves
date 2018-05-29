#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(LL i = a; a<=b; i++)
#define FOR(i, a, b)      for(LL i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

LL egcd(LL a, LL b, LL *x1, LL *y1)
{
    if(b==0){
    	*x1 = 1;
    	*y1 = 0;
    	return a;
    }
    LL x, y;
    LL g = egcd(b, a%b, &x, &y);
    *x1 = y;
    *y1 = x - (a/b)*y;
    return g;
}

int main()
{
    Read();
    Write();
    
    LL n;
    LL n1, n2, c1, c2;

    while(scanf("%lld", &n) && n){
    	LL bx = -1, by = -1, g, x1, y1;
        scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
        g = egcd(n1, n2, &x1, &y1);
        //printf("G: %lld %lld %lld\n", g, x1, y1);
        if(n%g){ printf("failed\n", n); continue; }

        x1 = x1 * (n/g);
        y1 = y1 * (n/g);

        n1 /= g;
        n2 /= g;

        //printf("%lld %lld\n", n1, n2);

        LL s = ceil((double)-x1/n2);
        LL e = floor((double)y1/n1);
        //printf("E%lld\n", e);

        //printf("%lld %lld\n", s, e);

        LL cost = (c1*n2) - (c2*n1);
        //printf("%lld\n", cost);
        if(cost*s<cost*e){
            bx = x1 + (n2)*s;
            by = y1 - (n1)*s;
        }
        else{
            //printf(" ");
            bx = x1 + n2*e;
            by = y1 - n1*e;
        }
        if(bx<0 || by<0) printf("failed\n");
        else printf("%lld %lld\n", bx, by);

    }

    return 0;
}