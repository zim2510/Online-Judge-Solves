#include <bits/stdc++.h>

using namespace std;

long long tzero(long long n)
{
    int c = 0;
    for(int i = 5; i<=n; i *= 5){
        c += n/i;
    }
    return c;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        long long n;
        int pos = 0;
        scanf("%lld", &n);
        long long lo = 0, hi = (n*5) + 5, mid, tz;
        while(hi-lo>=5){
            mid = (lo+hi)/2;
            tz = tzero(mid);
            if(tz>n){
                hi = mid;
            }
            else if(tz<n){
                lo = mid;
            }
            else if(tz==n){
                pos = 1;
                mid = (mid/5) * 5;
                break;
            }
        }
        printf("Case %d: ", i);
        if(pos) printf("%d\n", mid);
        else printf("impossible\n");
    }
}
