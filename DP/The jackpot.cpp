#include <bits/stdc++.h>

using namespace std;

int opt[10000], nums[10000], n, mx;

int dp(int ci)
{
    if(ci>=n) return 0;
    if(opt[ci]!=-1) return opt[ci];
    opt[ci] = nums[ci] + dp(ci+1);
    if(opt[ci]>mx) mx = opt[ci];
    return opt[ci];
}

int main()
{
    while(scanf("%d", &n)==1 && n){
        memset(opt, -1, sizeof(opt));
        mx = 0;
        for(int i = 0; i<n; i++){
            scanf("%d", &nums[i]);
        }
        dp(0);
        if(!mx) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", mx);

    }
}
