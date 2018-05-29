#include <bits/stdc++.h>
#define max3(a,b,c) max(max(a,b), c)

using namespace std;

int n, m;
int grid[100][100], opt[105][105];

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        scanf("%d %d", &n, &m);
        for(int i = 0; i<=n+1; i++){
            for(int j = 0; j<=m+1; j++) opt[i][j] = 0;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++) scanf("%d", &grid[i][j]);
        }
        int mx = 0;
        for(int i = n; i>0; i--){
            for(int j = 1; j<=m; j++){
                opt[i][j] = grid[i][j] + max3(opt[i+1][j-1], opt[i+1][j], opt[i+1][j+1]);
                if(opt[i][j]>mx) mx = opt[i][j];
            }
        }
        printf("%d\n", mx);
    }
}

