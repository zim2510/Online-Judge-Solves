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
#define MAX               1000000000
#define ff                first
#define ss                second
#define sf             	  scanf
#define pf 	              printf
#define MOD 			  1000000007

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

ULL ncr[1005][1005];

ULL nCr(int n, int r)
{
    if(ncr[n][r]!=-1) return ncr[n][r];
    if(n==r || r==0) return 1;
    return ncr[n][r] = ((nCr(n-1, r) + nCr(n-1, r-1)))%MOD;
}

ULL opt[1005][1005];

ULL calc(int n, int k)
{
    if(opt[n][k]!=-1) return opt[n][k];
    if(k==0) return 1;
    opt[n][k] = (k>=2?(k-1)*calc(n-2, k-2):0)%MOD + ((k-1) * calc(n-1, k-1))%MOD + ((n-k)*calc(n-1, k-1))%MOD;
    return opt[n][k]%MOD;
}

ULL fact[1005];

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    MEM(ncr, -1);
    MEM(opt, -1);

    fact[0] = 1;
    FOR(i, 1, 1005) fact[i] = (fact[i-1] * i)%MOD;


    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	int n, m, k;
    	sf("%d %d %d", &n, &m, &k);

    	ULL ashoSexKori = (((nCr(m, k) % MOD) * fact[n-m]) % MOD) * calc(n-k, m-k);

    	pf("Case %d: %llu\n", i, (ashoSexKori)%MOD);
    }

}