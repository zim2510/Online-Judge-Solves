#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<long long, int> soe;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        long long tim[100000];
        int n;
        scanf("%d", &n);
        for(int i = 0; i<(2*n); i+=2){
            scanf("%lld %lld", &tim[i], &tim[i+1]);
            tim[i+1]++;
            soe[tim[i]] += 1;
            soe[tim[i+1]] -= 1;
        }
        int cnt = 0, mx = 0;
        sort(tim, tim+2*n);
        for(int i = 0; i<2*n; i++){
            cnt += soe[tim[i]];
            soe[tim[i]] = 0;
            if(cnt>mx) mx = cnt;
        }
        printf("Case %d: %d\n", i, mx);
    }
}
