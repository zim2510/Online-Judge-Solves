#include <bits/stdc++.h>

using namespace std;

int n, coins[100], total, req, mx;
int opt[50001][101];

int dp(int sf, int ci)
{
    if(ci>=n) return 0;
    if(opt[sf][ci]!=-1) return opt[sf][ci];
    int n = 0;
    if(sf+coins[ci]<=req){
        n = coins[ci] + dp(sf+coins[ci], ci+1);
    }
    int m = dp(sf, ci+1);
    opt[sf][ci] = max(n, m);
    return opt[sf][ci];
}


int main()
{
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        memset(opt, -1, sizeof(opt));
        total = 0;
        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            scanf("%d", &coins[i]);
            total += coins[i];
        }

        req = total/2;

        mx = dp(0, 0);
        //printf("%d\n", mx);

        printf("%d\n", ((total-mx) - mx));
    }
}
