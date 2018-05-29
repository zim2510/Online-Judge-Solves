#include <bits/stdc++.h>

using namespace std;

int sz, n;
int w[2000], v[2000];
int dptbl[2000][2000];

int dp(int wsf, int ci)
{
    if(ci>=n) return 0;
    if(dptbl[ci][wsf]!=-1) return dptbl[ci][wsf];
    int t = 0;
    if(wsf+w[ci]<=sz){
        t = v[ci] + dp(wsf+w[ci], ci+1);
    }
    int nt = dp(wsf, ci+1);
    int r = max(t, nt);
    dptbl[ci][wsf] = r;
    return dptbl[ci][wsf];
}

int main()
{
    scanf("%d %d", &sz, &n);
    for(int i = 0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    memset(dptbl, -1, sizeof(dptbl));
    int r = dp(0, 0);
    printf("%d\n", r);
}
