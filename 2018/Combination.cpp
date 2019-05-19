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

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

LL bigmod(LL n, LL p, LL m)
{
	if(!p) return 1;
	if(p&1) return (n*bigmod(n, p-1, m))%m;
	LL x = bigmod(n, p/2, m);
	return (x*x)%m;
}

LL fac[1000005];
LL 	rev[1000005];

void calc(){
	fac[0] = 1;
	rev[0] = 1;
	FOR(i, 1, 1000005){
		fac[i] = (fac[i-1]*i)%1000003;
		rev[i] = (rev[i-1]*bigmod(i, 1000001, 1000003))%1000003;
	}
}


int main(int argc, char const *argv[])
{
	Read();
	Write();

	calc();
	int tc;
	sf("%d", &tc);
	TC(i, 1, tc){
		int n, r;
		sf("%d %d", &n, &r);
		LL ans = (((fac[n]*rev[r])%1000003)*rev[n-r])%1000003 + 1000003;
		printf("Case %d: %lld\n", i, ans%1000003);

	}
}