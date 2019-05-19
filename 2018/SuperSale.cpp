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

int opt[1000][1000];
int w[1000], p[1000];
int n;

int dp(int ci, int rem)
{
	if(ci==n) return 0;
	if(opt[ci][rem]!=-1) return opt[ci][rem];
	return opt[ci][rem] = max(dp(ci+1, rem), w[ci]<=rem?p[ci]+dp(ci+1, rem-w[ci]):0);
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	sf("%d", &tc);
	TC(i, 1, tc){
		MEM(opt, -1);
		sf("%d", &n);
		FOR(i, 0, n){
			sf("%d %d", &p[i], &w[i]);
		}
		int res = 0;
		int m;
		sf("%d", &m);
		FOR(i, 0, m){
			int carry;
			sf("%d", &carry);
			res += dp(0, carry);
		}
		printf("%d\n", res);
	}
}
