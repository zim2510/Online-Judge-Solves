#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll stree[100000];
ll pp[150000];
ll chk[100000];


void treecalc()
{
    stree[0] = 1;
    stree[1] = 1;

    for(int i = 2; i<5000; i++){
        long long t = 0;
        for(int x = 0; x<i; x++){
            t = (t + (stree[x] * stree[i-x-1])%100000007) % 100000007;
        }
        stree[i] = t;
    }
}

void perfcalc()
{
    ll x = 0, r = 1;
    pp[x++] = 0;
    for(long long int i = 2; i<100000; i++){
        r = i;
        if(chk[i]) continue;

        while(1){
            r *= i;
            if(r<100000) chk[r]++;
            if(r>10000000000) break;
            pp[x++] = r;
        }
    }
    sort(pp, pp+x);
    int c = 0;
    pp[x] = 10000000010;
}

int bs1(ll n)
{
    int lo = 0, hi = 102231;

    while(lo <= hi)
    {
        int mid = (hi+lo)/2;
        if(pp[mid]>=n && pp[mid-1]<n) return mid;
        else if(pp[mid]>n) hi = mid-1;
        else lo = mid+1;
    }
}

int bs2(ll n)
{
    int lo = 0, hi = 102231;
    while(lo <= hi)
    {
        int mid = (hi+lo)/2;
        if(pp[mid]<=n && pp[mid+1]>n) return mid;
        else if(pp[mid]>n) hi = mid-1;
        else lo = mid+1;
    }
}


int main()
{

    perfcalc();
    treecalc();
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        ll a, b;
        scanf("%lld %lld", &a, &b);
        int ep = bs2(b);
        int sp = bs1(a);
        int n = ep - sp + 1;
        if(!n) printf("Case %d: 0\n", i);
        else printf("Case %d: %lld\n", i, stree[n]);
    }

    return 0;
}
