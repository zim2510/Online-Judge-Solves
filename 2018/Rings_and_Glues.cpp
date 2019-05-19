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

class disset{
	public:
	vector <int> par;
	vector <int> sz;
	disset(int n)
	{
		par.resize(n);
		sz.resize(n);
		for(int i = 0; i<n; i++){ par[i] = i; sz[i] = 1; } 
	}

	int Find(int node)
	{
	    if(par[node]==node) return node;
	    par[node] = Find(par[node]);
	    return par[node];
	};

	int Union(int node1, int node2)
	{
	    int x = Find(node1);
	    int y = Find(node2);
	    if(x!=y){
	    	par[x] = y;
	    	sz[y] += sz[x];
	    }
	    return sz[y];
	}
};

bool sameset(pair< pair <double, double>, double> x, pair< pair <double, double>, double> y)
{
	double dis = SQR(x.ff.ff-y.ff.ff) + SQR(x.ff.ss - y.ff.ss);
	if(x==y) return 1;
	return dis < SQR(x.ss+y.ss) && dis > SQR(x.ss-y.ss);
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int n;
    while(scanf("%d", &n) && n!=-1){
    	disset X(n);
    	vector < pair< pair <double, double>, double> > pts(n);
    	for(int i = 0; i<n; i++){
    		scanf("%lf %lf %lf", &pts[i].ff.ff, &pts[i].ff.ss, &pts[i].ss);
    	}
    	int mx = min(1, n);
    	for(int i = 0; i<n; i++){
    		for(int j = i+1; j<n; j++){
    			if(sameset(pts[i], pts[j])){
    				mx = max(mx, X.Union(i, j));
    			}
    		}
    	}
    	printf("The largest component contains %d ring%s.\n", mx, mx==1?"":"s");
    }
}
