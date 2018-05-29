#include <bits/stdc++.h>

using namespace std;

int opt[100][100];
int n, m, ns1[100], ns2[100];

int dp(int i, int j)
{
    if(i>=n || j>=m) return 0;
    if(opt[i][j]!=-1) return opt[i][j];
    if(ns1[i]==ns2[j]) opt[i][j] = 1 + dp(i+1, j+1);
    else opt[i][j] = max(dp(i, j+1), dp(i+1, j));
    return opt[i][j];
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int i = 1;
    while(scanf("%d %d", &n, &m) && (n || m)){
        memset(opt, -1, sizeof(opt));
        for(int i = 0; i<n; i++) scanf("%d", &ns1[i]);
        for(int i = 0; i<m; i++) scanf("%d", &ns2[i]);
        int x = dp(0, 0);
        printf("Twin Towers #%d\n", i++);
        printf("Number of Tiles : %d\n\n", x);
    }
}
