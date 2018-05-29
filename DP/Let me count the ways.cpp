#include <bits/stdc++.h>

using namespace std;

unsigned long long opt[4][30005];
int cents[] = {50, 25, 10, 5};

unsigned long long dp(int m, int ct)
{
    if(m<0) return 0;
    if(m==0 || ct==4) return 1;
    if(opt[ct][m]) return opt[ct][m];
    opt[ct][m] = dp(m, ct+1) + dp(m-cents[ct], ct);
    return opt[ct][m];
}

int main()
{
    int n;
    while(scanf("%d", &n)==1){
        unsigned long long x = dp(n, 0);
        if(x==1) printf("There is only 1 way to produce %d cents change.\n", n);
        else printf("There are %llu ways to produce %d cents change.\n", x, n);
    }
}
