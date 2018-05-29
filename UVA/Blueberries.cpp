#include <bits/stdc++.h>

using namespace std;

int opt[1000][1000];
int bbry[1000];
int mx, n;

int dp(int tsf, int ci)
{
    if(ci>=n) return 0;
    if(opt[ci][tsf]!=-1) return opt[ci][tsf];
    if(bbry[ci]+tsf<=mx) opt[ci][tsf] = max(bbry[ci]+dp(tsf+bbry[ci], ci+2), dp(tsf, ci+1));
    else opt[ci][tsf] = dp(tsf, ci+1);
    return opt[ci][tsf];
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        scanf("%d %d", &n, &mx);
        for(int i = 0; i<n; i++) scanf("%d", &bbry[i]);
        memset(opt, -1, sizeof(opt));
        printf("Scenario #%d: %d\n", i, dp(0, 0));
    }
}
