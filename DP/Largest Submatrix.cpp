#include <bits/stdc++.h>

using namespace std;

int tbl[26][26];

int main()
{
    int tc;
    string in[26];
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        if(i>1) printf("\n");
        cin>>in[1];
        int n = in[1].size();
        for(int i = 2; i<=n; i++){
            cin>>in[i];
        }
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=n; j++){
                if(in[i][j]=='1') tbl[i][j] = tbl[i-1][j] + 1;
                else tbl[i][j] = 0;
            }
        }
        int mx = 0;
        for(int r1 = 1; r1<=n; r1++){
            for(int r2 = r1; r2<=n; r2++){
                int last = 0;
                for(int c = 0; c<n; c++){
                    int v = tbl[r2][c] - tbl[r1-1][c];
                    if(v==r2-r1+1) last = last+v;
                    else last = 0;
                    if(last>mx) mx = last;
                }
            }
        }
        printf("%d\n", mx);

    }
}
