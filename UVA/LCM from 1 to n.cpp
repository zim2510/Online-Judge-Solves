#include <bits/stdc++.h>
 
#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               100000000
#define ff                first
#define ss                second
#define sf                scanf
#define pf                printf
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;
 
int prime[MAX>>6];
int nprime[5761455];
unsigned int mul[100001];
int nprimes = 0;
 
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int sset(int N,int pos){    return N=N | (1<<pos);}
 
void siv()
{
    for(int i = 3; i<10000; i+=2){
        if(!check(prime[i>>6], (i&((1<<7)-1))>>1))
            for(int x = i*i; x<MAX; x+=2*i)
                prime[x>>6] = sset(prime[x>>6], (x&((1<<7)-1))>>1);
    }
    nprime[nprimes++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!check(prime[i>>6], (i&((1<<7)-1))>>1))
            nprime[nprimes++] = i;
    }
}
 
void calc()
{
    int n = 0, x = 0;
    mul[0] = 1;
    for(int i = 1; i<=100000; i++){
        mul[i] = mul[i-1];
        while(nprime[x]<=i*1000 && x<nprimes){
            mul[i] *= nprime[x];
            x++;
        }
    }
}
 
int main()
{
    //Read();
    //Write();
    siv();
    calc();
    int tc;
    sf("%d", &tc);
    TC(i, 1, tc){
        int n;
        sf("%d", &n);
        unsigned int result = mul[n/1000];
        int sp = upper_bound(nprime, nprime+nprimes, (n/1000)*1000) - nprime;
        for(int i = sp; nprime[i]<=n && i<nprimes; i++) result *= nprime[i];
        for(int i = 0; nprime[i]*nprime[i]<=n && i<nprimes; i++){
            int x = n;
            while(x>=nprime[i]*nprime[i]) result *= nprime[i], x/=nprime[i];
        }
        pf("Case %d: %lu\n", i, result);
    }
    return 0;
}