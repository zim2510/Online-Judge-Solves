#include <bits/stdc++.h>

using namespace std;

int path[1000001], grid[1000001];

void ppath(int n)
{
    if(path[n]!=0) ppath(path[n]);
    printf("%d ", n);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    grid[1] = 0;
    path[1] = 0;
    int n = 1000000;
    for(int i = 1; i<=n; i++){
        if(i*3<=n && (grid[i*3]==0 || grid[i]<grid[i*3])) grid[i*3] = grid[i] + 1, path[i*3] = i;
        if(i*2<=n && (grid[i*2]==0 || grid[i]<grid[i*2])) grid[i*2] = grid[i] + 1, path[i*2] = i;
        if(i+1<=n && (grid[i+1]==0 || grid[i]<grid[i+1])) grid[i+1] = grid[i] + 1, path[i+1] = i;
    }
    while(scanf("%d", &n)==1){
        printf("%d\n", grid[n]);
        //ppath(path[n]);
        //printf("%d\n", n);
    }
}
