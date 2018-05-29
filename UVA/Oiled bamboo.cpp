#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int n;
        int sticks[100000];
        scanf("%d\n", &n);
        sticks[0] = 0;
        for(int i = 1; i<n+1; i++){
            scanf("%d", &sticks[i]);
        }
        int jumps[100000];
        for(int i = 1; i<n+1; i++){
            jumps[i-1] = sticks[i] - sticks[i-1];
        }
        sort(jumps, jumps+n, greater<int>());
        int init = jumps[0];
        int ans = init;
        for(int i = 1; i<n+1; i++){
            if(sticks[i]-sticks[i-1] == init) init--;
            else if(sticks[i]-sticks[i-1]>init){
                ans++;
                break;
            }
        }
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
