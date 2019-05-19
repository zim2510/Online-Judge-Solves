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

LL nCr(int n, int r)
{
	if(ncr[n][r]!=-1) return ncr[n][r];
	if(n==r || r==0) return 1;
	return ncr[n][r] = ((nCr(n-1, r) + nCr(n-1, r-1)))%MOD;
}

ULL npr[1005][1005];

ULL nPr(int n, int r)
{
	if(npr[n][r]!=-1) return npr[n][r];
	if(n==0 || r==0)  return 1;
	return npr[n][r] = ((n*(nPr(n-1, r-1))))%MOD;
}

LL opt[1005][1005];

LL calc(int block, int freenums)
{
	if(block<=0) return nPr(freenums, freenums);
	if(opt[block][freenums]!=-1) return opt[block][freenums];

	LL o1 = (block-1) * calc(block-2, freenums);
	LL o2 = (block-1) * calc(block-1, freenums);
	LL o3 = freenums  * calc(block-1, freenums);

	return opt[block][freenums] = (o1+o2+o3)%MOD;
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    MEM(ncr, -1);
    MEM(npr, -1);

    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	LL n, m, k;
    	sf("%lld %lld %lld", &n, &m, &k);

    	MEM(opt, -1);

    	ULL ans = (nCr(m, k) * calc(m-k, n-m));
    	pf("Case %d: %llu\n", i, (ans)%MOD);
    }

}
