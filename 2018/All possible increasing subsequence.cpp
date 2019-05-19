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

int BIT[100005];

int query(int n)
{
	int res = 0;
	while(n>0){
		res += BIT[n];
		n -= (n&-n);
	}
	return res;
}

void update(int n)
{
	while(n<100005){
		BIT[n] += 1;
		n += (n&-n);
	}
}

int bigmod(int n, int p, int mod)
{
	if(p==0) return 1;
	if(p&1) return (n*bigmod(n, p-1, mod))%mod; 
	LL x = bigmod(n, p/2, mod);
	return (x*x)%mod;
}

int main(int argc, char const *argv[])
{
	Read();
    Write();
    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	MEM(BIT, 0);
    	int n;
    	scanf("%d", &n);
    	int ans = 0;
    	FOR(i, 0, n){
    		int t;
    		scanf("%d", &t);
    		//cout<<query(t-1)<<endl;
    		cout<<ans<<" "<<bigmod(2, query(t-1)+1, 1000000007)-1<<endl;
    		ans = (ans + bigmod(2, query(t-1)+1, 1000000007)-1)%1000000007;
    		update(t);
    	}
    	printf("Case %d: %d\n", i, ans);
    }
}
