#include <bits/stdc++.h>
#define max3(a,b,c) max(max(a,b), c)
using namespace std;

int grid[100][100], n, m, opt[100][100];

int dp(int cn, int cm)
{
    if(cn>=n || cm>=m || cm<0) return 0;
    if(opt[cn][cm]!=-1) return opt[cn][cm];
    opt[cn][cm] = grid[cn][cm] + max3(dp(cn+1, cm-1), dp(cn+1, cm), dp(cn+1, cm+1));
    return opt[cn][cm];
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        memset(opt, -1, sizeof(opt));
        scanf("%d %d", &n, &m);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) scanf("%d", &grid[i][j]);
        }
        int mx = 0;
        for(int i = 0; i<m; i++){
            if(dp(0, i)>mx) mx = dp(0, i);
        }
        printf("%d\n", mx);
    }
}
