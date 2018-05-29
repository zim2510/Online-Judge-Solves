#include <bits/stdc++.h>

int opt[101][101][101];


int dp(int n, int k, int p)
{
    if(k==1){
        if(n>=p) return 1;
        else return 0;
    }
    if(opt[n][k][p]!=-1) return opt[n][k][p];
    opt[n][k][p] = 0;
    for(int i = p; i<=n; i++){
        opt[n][k][p] += dp(n-i, k-1, p);
        //opt[n][k][p] = opt[n][k]%1000000;
    }
    return opt[n][k][p];
}



int main()
{
    int n, k, p;
    memset(opt, -1, sizeof(opt));
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        scanf("%d %d %d", &k, &n, &p);
        printf("%d\n", dp(n, k, p));
    }
}

