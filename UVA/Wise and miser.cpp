#include <bits/stdc++.h>
#define min3(a,b,c) min(min(a,b), c)
using namespace std;

int opt[100][100];
int n, m;
int grid[100][100];

int dp(int ci, int last)
{
    if(ci>=n) return 0;
    if(opt[ci][last]!=-1) return opt[ci][last];
    int r;
    if(last!=0 && last+1!=m) r = min3(grid[ci][last-1]+dp(ci+1, last-1), grid[ci][last]+dp(ci+1, last), grid[ci][last+1]+dp(ci+1, last+1));
    else if(last==0) r = min(grid[ci][last]+dp(ci+1, last), grid[ci][last+1]+dp(ci+1, last+1));
    else if(last==m-1) r = min(grid[ci][last-1]+dp(ci+1, last-1), grid[ci][last]+dp(ci+1, last));
    opt[ci][last] = r;
    //printf("CI: %d Last: %d R: %d\n", ci, last, r);
    return opt[ci][last];

}


int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    memset(opt, -1, sizeof(opt));
    int mn = INT_MAX;
    for(int i = 0; i<m; i++){
        int t = dp(0, i);
        //printf("%d\n", t);
        if(t<mn) mn = t;
    }
    printf("%d\n", mn);
}
