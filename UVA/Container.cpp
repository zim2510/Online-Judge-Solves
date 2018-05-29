#include <bits/stdc++.h>

using namespace std;

int v, c;
long long vsl[1000001];
long long bin(long long hi, long long lo);

int main()
{
    freopen("out.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        long long mx = 0;
        scanf("%d %d", &v, &c);


        long long hi = 0;
        for(int i = 0; i<v; i++){
            scanf("%lld", &vsl[i]);
            hi += vsl[i];
            if(vsl[i]>mx) mx = vsl[i];
        }

        if(v<=c){
            printf("Case %d: %d\n", i, mx);
            continue;
        }

        else if(c==1){
            printf("Case %d: %lld\n", i, hi);
            continue;
        }

        long long mid = bin(hi, mx);
        printf("Case %d: %d\n", i, mid);
    }
}

long long bin(long long hi, long long lo)
{
    long long mid;

    while(hi!=lo){
        mid = (hi+lo)/2;
        if(hi == lo) break;
        long long p = 0, np = 1;
        for(int i = 0; i<v; i++){
            if(p+vsl[i]<=mid) p += vsl[i];
            else{
                p = vsl[i];
                np++;
            }
        }
        printf("Part: %lld\n", np);

        if(np<=c) hi = mid;
        else lo = mid;
    }
    return mid;
}
