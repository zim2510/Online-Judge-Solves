#include <bits/stdc++.h>

using namespace std;

int in[200][200], n;
int opt[200][200];

int dp(int ci, int cj, int cn)
{
    if(ci>=(n*2-1) || cj>=cn || cj<0) return 0;
    if(opt[ci][cj]!=-1) return opt[ci][cj];
    if(ci<n-1) opt[ci][cj] = in[ci][cj] + max(dp(ci+1, cj+1, cn+1), dp(ci+1, cj, cn+1));
    else opt[ci][cj] = in[ci][cj] + max(dp(ci+1, cj-1, cn-1), dp(ci+1, cj, cn-1));
    return opt[ci][cj];

}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i; j++){
                scanf("%d", &in[i][j]);
            }
        }
        for(int i = n; i<n*2-1; i++){
            for(int j = 0; j<((n*2-1)-i); j++){
                scanf("%d", &in[i][j]);
            }
        }
        memset(opt, -1, sizeof(opt));
        int x = dp(0, 0, 1);
        printf("Case %d: %d\n", i, x);
    }
}
