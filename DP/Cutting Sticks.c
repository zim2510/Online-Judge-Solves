#include <bits/stdc++.h>

using namespace std;

int len, n, cp[51];
int opt[51][51];

int dp(int ci, int ce)
{
    if(opt[ci][ce]!=-1) return opt[ci][ce];
    if(ce-ci<=1) return 0;
    int m = INT_MAX, t = INT_MAX;
    int i;
    for(i = ci+1; i<ce; i++){
        if(cp[i]>cp[ci] && cp[i]<cp[ce]){
            t = dp(ci, i) + dp(i, ce);
        }
        if(t<m) m = t;
    }
    opt[ci][ce] = (cp[ce] - cp[ci]) + m;
    return opt[ci][ce];

}

int main()
{
    cp[0] = 0;
    int i, j;
    while(scanf("%d", &len) && len){
        scanf("%d", &n);
        cp[n+1] = len;
        memset(opt, -1, sizeof(opt));
        for(i = 1; i<=n; i++) scanf("%d", &cp[i]);
        printf("The minimum cutting is %d.\n", dp(0, n+1));
    }
}
