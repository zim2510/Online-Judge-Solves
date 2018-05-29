#include <bits/stdc++.h>
#define min3(a,b,c) min(max(a,b), c)

using namespace std;

int n, m;
int grid[105][105];
int opt[105][105];
int nxt[105];

int dp(int cn, int cm)
{
    if(cm>=m) return 0;
    if(opt[cn][cm]!=0) return opt[cn][cm];
    opt[cn][cm] = grid[cn][cm];


    int mn = INT_MAX;
    for(int i = -1; i<2; i++){
        int x = (cn + i)>=0 ? (cn+i)%n : n-1;
        int t = dp(x, cm+1);
        if(t<mn) mn = t;
    }
    opt[cn][cm] += mn;
    return opt[cn][cm];
}

void poscalc(int cm, int cn)
{
    if(cm==m-1) return;
    int m = INT_MAX;
    nxt[cm] = 1000;
    for(int i = -1; i<=1; i++){
        int x = (cn+i)<0?n-1:(cn+i)%n;
        if(opt[x][cm+1]<m || (opt[x][cm+1]<=m && nxt[cm]-1>x)){
            m = opt[x][cm+1];
            nxt[cm] = x + 1;
        }
    }
    poscalc(cm+1, nxt[cm]-1);
}

int main()
{
    while(scanf("%d %d", &n, &m)==2){
        for(int i = 0; i<100; i++){
            for(int j=0; j<100; j++) opt[i][j] = 0;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) scanf("%d", &grid[i][j]);
        }

        int x, mn = INT_MAX;
        for(int i = 0; i<n; i++){
            int t = dp(i, 0);
            if(t<mn){
                mn = t;
                x = i;
            }
        }
        poscalc(0, x);
        printf("%d", x+1);
        for(int i = 0; i<m-1; i++){
            printf(" %d", nxt[i]);
        }
        printf("\n");
        printf("%d\n", mn);
    }
}
