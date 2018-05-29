#include <bits/stdc++.h>
#define M 10000
using namespace std;

int opt[10000][10000];

int dp(long long n, int lim)
{
    if(n==1) return 1;
    if(n>lim) return 0;
    if(n>=M || lim>=M){
        if(n%2) return 1+dp(3*n+1,lim);
        else return 1+dp(n/2,lim);
    }
    if(opt[n][lim]!=0) return opt[n][lim];
    if(n%2) opt[n][lim] = 1 + dp(n*3+1, lim);
    else opt[n][lim] = 1 + dp(n/2, lim);
    return opt[n][lim];
}

int main()
{
    int n, lim, i = 1;
    while(scanf("%d %d", &n, &lim) && (n>=0 && lim>=0)){
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", i++, n, lim, dp(n, lim));
    }
}

