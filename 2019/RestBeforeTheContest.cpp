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

bool possible = 0;
int n, m, r;
int opt[505][55][55], energy[505];

int dp(int ci, int inarow, int slept)
{
	if(slept==m) { possible = 1; return 0; }
	if(ci==n) return -1000000000;

	if(opt[ci][inarow][slept]!=-1) return opt[ci][inarow][slept];
	int &ret = opt[ci][inarow][slept];
	ret = dp(ci+1, 1, slept);
	if(inarow<=r) ret = max(ret, (inarow*energy[ci]) + dp(ci+1, inarow+1, slept+1));
	return ret;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();

	sf("%d %d %d", &n, &m, &r);

	FOR(i, 0, n) sf("%d", &energy[i]);

	MEM(opt, -1);
	int result = dp(0, 1, 0);
	if(possible) cout<<result<<endl;
	else cout<<-1<<endl;
}
