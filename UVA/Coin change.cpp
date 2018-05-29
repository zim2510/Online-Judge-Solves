#include <bits/stdc++.h>

using namespace std;

vector <long long> total, etotal;
int coin[30];
long long n, k, req;
int c = 0;

void calcodd(long long ltotal, long long i)
{
    if(i>=n) total.push_back(ltotal);
    if(i>=n) return;
    calcodd(ltotal, i+2);
    calcodd(ltotal+coin[i], i+2);
    return;
}

void calceven(long long ltotal, long long i)
{
    if(i>=n) etotal.push_back(ltotal);
    if(i>=n) return;
    calceven(ltotal, i+2);
    calceven(ltotal+coin[i], i+2);
    return;
}

int bin(int lo, int hi)
{
    int mid;
    if(total[hi]<=req) return hi+1;
    if(total[lo]>req && req!=k) return 1;
    if(total[lo]>req && req==k) return 0;

    while(hi-lo>1)
    {
        mid = (lo + hi) / 2;
        if(total[mid]<=req) lo = mid;
        else if(total[mid]>req) hi = mid;
    }
    //printf("R: %lld Found: %d\n", req, lo);

    if(lo>=0) return lo+1;
    else return 0;

}

int main()
{
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);


    for(int i = 1; i<=tc; i++){
        long long int cnt = 0;
        scanf("%lld %lld", &n, &k);
        for(int i = 0; i<n; i++) scanf("%d", &coin[i]);

        total.clear();
        etotal.clear();
        calcodd(0, 0);
        calceven(0, 1);

        long long odds = total.size();
        long long evs = etotal.size();

        sort(etotal.begin(), etotal.end());
        for(int i = 0; i<evs; i++) printf("Sack 1: %lld\n", etotal[i]);
        sort(total.begin(), total.end());
        for(int i = 0; i<odds; i++) printf("Sack 2: %lld\n", total[i]);

        for(int i = 0; i<evs; i++){
            req = k - etotal[i];
            if(req>=0) cnt += bin(0, odds-1);
        }
        printf("Case %d: %lld\n", i, cnt);
    }
}

