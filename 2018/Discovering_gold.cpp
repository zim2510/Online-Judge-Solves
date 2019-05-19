#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out


.txt", "w", stdout)
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

int n;
vector <int> coin;
vector <double> opt;

double exval(int ci)
{
	if(ci==n) return (double) coin[ci];
	if(opt[ci]!=-1) return opt[ci];

	int impos = 6 - min(n - ci, 6);
	double res = coin[ci];
	double tres = 0;
	for(int i = 1; i<=6-impos; i++){
		tres += exval(ci+i);
	}
	res = res + (tres)/(6.0-impos);
	return opt[ci] = res;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		scanf("%d", &n);
		coin.resize(n+1);
		opt.clear();
		opt.resize(n+1, -1);
		TC(i, 1, n){
			scanf("%d", &coin[i]);
		}
		printf("Case %d: %0.6f\n", i, exval(1));
	}
}
