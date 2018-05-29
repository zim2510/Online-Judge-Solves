#include <bits/stdc++.h>

using namespace std;

int matrix[101][101], sum[101][101];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            scanf("%d", &matrix[i][j]);
            sum[i][j] = matrix[i][j] + sum[i-1][j];
        }
    }

    int mx = INT_MIN;
    int mx2;

    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            mx2 = 0;
            for(int c = 1; c<=n; c++){
                int val = sum[j][c] - sum[i-1][c];
                mx2 = max(val, val+mx2);
                if(mx2>mx) mx = mx2;
            }
        }
    }
    printf("%d\n", mx);

}
