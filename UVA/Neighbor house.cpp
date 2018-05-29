#include <bits/stdc++.h>

using namespace std;

int opt[20][3];
int n, house[20][3];
int dp(int ci, int last)
{
    if(ci>=n) return 0;
    if(opt[ci][last]!=-1) return opt[ci][last];
    int r;
    if(last==2) r = min(house[ci][0]+dp(ci+1, 0), house[ci][1]+dp(ci+1, 1));
    if(last==1) r = min(house[ci][0]+dp(ci+1, 0), house[ci][2]+dp(ci+1, 2));
    if(last==0) r = min(house[ci][2]+dp(ci+1, 2), house[ci][1]+dp(ci+1, 1));
    opt[ci][last] = r;
    return opt[ci][last];
}


int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
        }
        memset(opt, -1, sizeof(opt));
        int r = min(dp(0, 0), dp(0,1));
        r = min(r, dp(0, 2));
        printf("Case %d: %d\n", i, r);
    }
}
