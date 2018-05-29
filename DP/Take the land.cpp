#include <bits/stdc++.h>

using namespace std;

int matrix[101][101], sum[101][101];

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) && n && m){
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                scanf("%d", &matrix[i][j]);
                matrix[i][j] = !matrix[i][j];
                sum[i][j] = matrix[i][j] + sum[i-1][j];
            }
        }

        int mx = INT_MIN;
        int mx2;

        for(int i = 1; i<=n; i++){
            for(int j = i; j<=n; j++){
                mx2 = 0;
                for(int c = 1; c<=m; c++){
                    int val = sum[j][c] - sum[i-1][c];
                    if(val!=j-i+1) mx2 = 0;
                    else mx2 += val;
                    if(mx2>mx) mx = mx2;
                }
            }
        }
        printf("%d\n", mx);
    }

}
