#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int n;
        scanf("%d", &n);
        int in[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                scanf("%d", &in[i][j]);
            }
        }
        printf("Case %d: ", i);
        int rs = 0, cs = 0, re = n - 1, ce = n-1;
        while(1){
            if(rs>re || cs>ce) break;
            for(int i = cs; i<=ce; i++){
                printf("%d", in[cs][i]);
                if(rs!=re || cs!=ce) printf(" ");
            }
            rs++;

            for(int i = rs; i<=re; i++){
                printf("%d", in[i][re]);
                if(rs!=re || cs!=ce) printf(" ");
            }
            ce--;

            for(int i = ce; i>=cs; i--){
                printf("%d", in[re][i]);
                if(rs!=re || cs!=ce) printf(" ");
            }
            re--;

            for(int i = re; i>=rs; i--){
                printf("%d", in[i][cs]);
                if(rs!=re || cs!=ce) printf(" ");
            }
            cs++;
        } printf("\n");


    }
}
