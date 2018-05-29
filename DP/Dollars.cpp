#include <bits/stdc++.h>

using namespace std;

int cents[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long opt[11][30005];

long long dp(int t, int typ)
{
    if(t==0) return 1;
    if(t<0 || typ>10) return 0;
    if(opt[typ][t]!=-1) return opt[typ][t];
    opt[typ][t] = dp(t-cents[typ], typ) + dp(t, typ+1);
    return opt[typ][t];
}

int main()
{
    //freopen("out.txt", "w", stdout);
    double t;
    memset(opt, -1, sizeof(opt));
    while(scanf("%lf", &t) == 1 && t){
        int n = (t+0.0000001)*100;

        int s;
        if(t<10)  s = 2;
        else if(t<100) s = 1;
        else s = 0;
        for(int i = 0; i<s; i++) printf(" ");

        long long x = dp(n, 0);
        printf("%0.2lf", t);


        s = x==0 ? 1 : log10(x) + 1;
        for(int i = 0; i<17-s; i++) printf(" ");
        printf("%lld\n", x);
    }
}

