#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  50000

using namespace std;

int prime[MAX], nprime[5133];
int nprimes = 0;
map<int, int> cnt;
vector<int> nums;

void siv()
{
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
    }
    nprime[nprimes++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[nprimes++] = i;
    }
}

void increase(int n)
{
    for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
        if(n%nprime[i]==0){
            if(!cnt[nprime[i]]) nums.pb(nprime[i]);
            while(n%nprime[i]==0){
                cnt[nprime[i]]++;
                n /= nprime[i];
            }
        }
    }
    if(n!=1){
        if(!cnt[n]) nums.pb(n);
        cnt[n]++;
    }
}

void decrease(int n)
{
    for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
        while(n%nprime[i]==0){
            cnt[nprime[i]]--;
            n /= nprime[i];
        }
    }
    if(n!=1){
        cnt[n]--;
    }
}

int calc(int x)
{
    int res = 1;
    for(int i = 0; i<cnt[nums[x]]; i++) res *= nums[x];
    return res;
}


int main(int argc, char const *argv[])
{
    Read();
    Write();
    siv();
    int n, r;
    while(scanf("%d %d", &n, &r) && (n||r)){
        cnt.clear();
        nums.clear();
        int x = r;
        if(n-r>r) r = n - r;
        for(LL i = r+1; i<=n; i++){
            increase(i);
        }
        for(int i = 2; i<=n-r; i++){
            decrease(i);
        }
        int res = 1;
        for(int i = 0; i<nums.size(); i++){
            res *= calc(i);
        }
        printf("%d things taken %d at a time is %d exactly.\n", n, x, res);
    }
    return 0;
}
