#include <bits/stdc++.h>

using namespace std;

int opt[1000000];

int dp(int i)
{
    if(i==1) return 1;
    if(i>=1000000){
        if(i%2) return 1 + dp(i*3+1);
        else return 1 + dp(i/2);
    }
    if(opt[i]!=-1) return opt[i];
    if(i%2) opt[i] = 1 + dp(3*i+1);
    else opt[i] = 1 + dp(i/2);
    return opt[i];
}


int main()
{
    memset(opt, -1, sizeof(opt));
    int sp, ep;
    while(scanf("%d %d", &sp, &ep)==2){
        int x = min(sp, ep);
        int y = max(sp, ep);
        int mx = 0;
        for(int i = x; i<=y; i++){
            int r = dp(i);
            if(r>mx) mx = r;
        }
        printf("%d %d %d\n", sp, ep, mx);
    }
}
