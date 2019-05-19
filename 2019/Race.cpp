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
#define MOD				  10056

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

int opt[1005];

int calculate(int horses)
{
	if(opt[horses]!=-1) return opt[horses];
	if(horses==0) return 1;

	int ans = 0;
	for(int i = horses; i>=1; i--){
		ans += nCr(horses, i) * calculate(horses-i);
		ans %= MOD;
	}

	return opt[horses] = ans%MOD;	
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	MEM(ncr, -1);
	MEM(opt, -1);

	int tc;
	sf("%d", &tc);

	TC(i, 1, tc){
		int n;
		scanf("%d", &n);
		int result = calculate(n);
		printf("Case %d: %d\n", i, result);
	}
}
