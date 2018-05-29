#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int x, y, t = 0;
    while(scanf("%d %d", &x, &y) && (x || y)){
        int grid[101][101];
        memset(grid, 0, sizeof(grid));

        if(t>0) printf("\n");
        printf("Field #%d:\n", ++t);

        for(int i = 0; i<x; i++){

            char in[102];
            scanf(" %s", in);

            for(int j = 0; j<y; j++){
                if(in[j]=='*'){
                    grid[i][j] = -100;
                    if(i-1>=0){
                        if(j-1>=0) grid[i-1][j-1]++;
                        grid[i-1][j]++;
                        if(j+1<y) grid[i-1][j+1]++;
                    }
                    if(j-1>=0) grid[i][j-1]++;
                    if(j+1<y) grid[i][j+1]++;
                    if(i+1<x){
                        if(j-1>=0) grid[i+1][j-1]++;
                        grid[i+1][j]++;
                        if(j+1<=y) grid[i+1][j+1]++;
                    }
                }
            }
        }


        for(int i = 0; i<x; i++){
            for(int j = 0; j<y; j++){
                if(grid[i][j]<0) printf("*");
                else printf("%d", grid[i][j]);
            }
            printf("\n");
        }
    }
}
