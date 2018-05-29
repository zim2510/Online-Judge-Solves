#include <bits/stdc++.h>

using namespace std;

int n;
int msl[10000000];
int opt[10000000];


int dp(int ci)
{
    if(ci>=n) return 0;
    if(opt[ci]!=-1) return opt[ci];
    for(int i = ci+1; i<n; i++){
        if(msl[i]<=msl[ci]){
            int t = dp(i);
            if(t>opt[ci]) opt[ci] = t;
        }
    }
    opt[ci] += 1;
    return opt[ci];
}

int main()
{
    freopen("out.txt", "w", stdout);
    n = 0;
    int f;
    int tc = 1;
    while(scanf("%d", &f)==1 && f>=0){
        if(tc>1) printf("\n");
        n = 0;
        msl[n++] = f;
        while(scanf("%d", &msl[n++])==1 && msl[n-1]>=0);
        memset(opt, -1, sizeof(opt));
        int mx = 0;
        for(int i = 0; i<n; i++){
            int t = dp(i);
            if(t>mx) mx = t;
        }
        printf("Test #%d:\n", tc++);
        printf("  maximum possible interceptions: %d\n", mx);
    }
}
