#include <bits/stdc++.h>

using namespace std;

long long dptable[10000];
int sz;
int golds[10000];

long long dp(int ci)
{
    if(ci>=sz) return 0;
    if(dptable[ci]!=-1) return dptable[ci];
    dptable[ci] = max(golds[ci] + dp(ci+2), dp(ci+1));
    return dptable[ci];
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        scanf("%d", &sz);
        for(int i = 0; i<sz; i++) scanf("%d", &golds[i]);
        memset(dptable, -1, sizeof(dptable));
        printf("Case %d: %lld\n", i, dp(0));
    }
}
