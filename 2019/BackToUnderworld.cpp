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

vector <int> graph[20005];
vector <int> lvl(2);
vector <int> mark(20005);

void dfs(int node, int depth)
{
	if(mark[node]) return;
	if(!graph[node].size()) return;

	mark[node] = 1;
	lvl[depth]++;

	FOR(i, 0, graph[node].size()){
		dfs(graph[node][i], !depth);
	}
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
		int f;
		sf("%d", &f);

		FOR(i, 0, 20005) graph[i].clear();

		FOR(i, 0, f){
			int x, y;
			sf("%d %d", &x, &y);
			graph[x].pb(y);
			graph[y].pb(x);
		}

		mark.clear();
		mark.resize(20005, 0);

		int result = 0;
		FOR(i, 0, 20005){
			lvl[0] = lvl[1] = 0;
			dfs(i, 0);
			result += max(lvl[0], lvl[1]);
		}

		pf("Case %d: %d\n", i, result);
	}
}
