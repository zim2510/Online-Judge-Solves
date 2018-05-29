#include <bits/stdc++.h>

using namespace std;
int sol[1001], np[1001], n;
int opt[1001][1001];

int dp(int i, int j)
{
    if(i>n || j>n) return 0;
    if(opt[i][j]!=-1) return opt[i][j];
    if(sol[i]==np[j]) opt[i][j] = 1 + dp(i+1, j+1);
    else opt[i][j] = max(dp(i+1, j), dp(i, j+1));
    return opt[i][j];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    while(1){
        if(feof(stdin)) break;
        int tmp;
        for(int i=1; i<=n; i++){
            scanf("%d", &tmp);
            sol[tmp] = i;
        }
        string s;
        cin.ignore();
        while(getline(cin, s)){
            memset(opt, -1, sizeof(opt));
            stringstream ss(s);
            int i=1;
            while(ss>>tmp){
                np[tmp]=i;
                i++;
            }
            if(i!=n+1){
                n=tmp;
                break;
            }
            else printf("%d\n", dp(1,1));
        }
    }
}
