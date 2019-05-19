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

bool check(int N,int pos)	{ return (bool)(N & (1<<pos)); }
int sset(int N,int pos)		{	return N=N | (1<<pos);	   }

int opt[105][15][1500];
int mark[105][15][1500];
int marker = 0;

int base, digits, d;

int dp(int ci, int last, int state)
{
	if(ci>=d){
		return (1<<base == state+1);
	}
	if(mark[ci][last][state]==marker) return opt[ci][last][state];

	mark[ci][last][state] = marker;

	opt[ci][last][state] = 0;

	opt[ci][last][state] += (valid(last+1, 0, base-1))?dp(ci+1, last+1, sset(state, last+1)):0;
	opt[ci][last][state] += (valid(last-1, 0, base-1))?dp(ci+1, last-1, sset(state, last-1)):0;

	return opt[ci][last][state] %= 1000000007;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
		
	int tc;
	sf("%d", &tc);

	TC(i, 1, tc){
		sf("%d %d", &base, &digits);
		int cnt = 0;
		TC(i, 1, base-1){
			FOR(j, 0, digits){
				marker++;
				d = digits - j;
				cnt += dp(1, i, (1<<i));
				cnt %= 1000000007;
			}
		}
		pf("%d\n", cnt);
	}
}
