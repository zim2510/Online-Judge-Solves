#include <bits/stdc++.h>

using namespace std;

int opt[1000000];

long long dp(long long i)
{
    //printf("%d\n", i);
    if(i==1) return 1;
    if(i>=1000000){
        if(i%2) return 1 + dp(3*i+1);
        else return 1 + dp(i/2);
    }
    if(opt[i]!=0) return opt[i];
    if(i%2) opt[i] = 1 + dp(3*i+1);
    else opt[i] = 1 + dp(i/2);
    return opt[i];
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int sp, ep;
    while(scanf("%d %d", &sp, &ep) && (sp || ep)){
        int mx = 0, mxv = 0;
        int s = min(sp, ep);
        int e = max(sp, ep);
        for(int i = s; i<=e; i++){
            int t = dp(i);
            if(t>mxv) mx = i, mxv = t;
        }
        if(s==1 && e<=2) printf("Between %d and %d, %d generates the longest sequence of %d values.\n", s, e, 1, 3);
        else printf("Between %d and %d, %d generates the longest sequence of %d values.\n", s, e, mx, mxv-1);
    }
}
