#include <bits/stdc++.h>
#define min3(a,b,c) min(max(a,b), c)

using namespace std;

int n, m;
int grid[105][105];
int opt[105][105];
int nxt[105][105], fnxt[105];

int dp(int cn, int cm)
{
    if(cm>=m) return 0;
    if(opt[cn][cm]!=0) return opt[cn][cm];
    opt[cn][cm] = grid[cn][cm];


    int mn = INT_MAX;
    nxt[cn][cm] = INT_MAX;
    for(int i = -1; i<2; i++){
        int x = (cn+i)<0?n-1:(cn+i)%n;
        int t = dp(x, cm+1);
        if(t<mn || (t<=mn && nxt[cn][cm]-1>x)){
            mn = t;
            nxt[cn][cm] = x + 1;
        }
    }
    opt[cn][cm] += mn;
    return opt[cn][cm];
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
                fnxt[0] = i+1;
                for(int i = 1; i<m; i++){
                    fnxt[i] = nxt[fnxt[i-1]-1][i-1];
                }
            }
        }
        printf("%d", fnxt[0]);
        for(int i = 1; i<m; i++){
            printf(" %d", fnxt[i]);
        }
        printf("\n");
        printf("%d\n", mn);
    }
}
