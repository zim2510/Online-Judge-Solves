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

double distance(ii x, ii y)
{
	return sqrt(SQR(x.ff-y.ff) + SQR(x.ss-y.ss));
}

class disset{
	public:
	std::vector <int> par;
	disset(int n)
	{
		par.resize(n);
		for(int i = 0; i<n; i++) par[i] = i;
	}

	int Find(int node)
	{
	    if(par[node]==node) return node;
	    par[node] = Find(par[node]);
	    return par[node];
	};

	void Union(int node1, int node2)
	{
	    int x = Find(node1);
	    int y = Find(node2);
	    par[x] = y;
	}
};

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    
    int n;;
    while(scanf("%d", &n) && n){
    	vector <ii> pts(n);
    	disset X(n);
    	vector<pair<double, ii>> edges;
    	int p, q;
    	scanf("%d %d", &p, &q);
    	if(p>q) swap(p, q);
    	FOR(i, 0, n) sf("%d %d", &pts[i].ff, &pts[i].ss);
    	double result = 0;
    	FOR(i, 0, n){
    		FOR(j, i+1, n){
    			double dis = distance(pts[i], pts[j]);
    			edges.pb({dis, {i, j}});
    			if(i==p-1 && j==q-1){
    				result += distance(pts[i], pts[j]);
    				X.Union(i, j);
    			}
    		}
    	}
    	sort(edges.begin(), edges.end());
    	for(int i = 0; i<edges.size(); i++){
    		if(X.Find(edges[i].ss.ff)!=X.Find(edges[i].ss.ss)){
    			result += edges[i].ff;
    			X.Union(edges[i].ss.ff, edges[i].ss.ss);
    		}
    	}
    	printf("%0.2lf\n", result);
    }
}
