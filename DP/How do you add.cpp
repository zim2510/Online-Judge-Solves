#include <bits/stdc++.h>

int opt[101][101];


int dp(int n, int k)
{
    if(k==1) return 1;
    if(opt[n][k]!=-1) return opt[n][k];
    opt[n][k] = 0;
    for(int i = 0; i<=n; i++){
        opt[n][k] += dp(n-i, k-1);
        opt[n][k] = opt[n][k]%1000000;
    }
    return opt[n][k];
}



int main()
{
    int n, k;
    memset(opt, -1, sizeof(opt));
    while(scanf("%d %d", &n, &k)==2){
        if(n||k) printf("%d\n", dp(n, k));
        else break;
    }
}
