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
#define MAX               10000
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

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	int n;
	sf(" %d ", &n);

	vector <string> grid(n);
	vector <vector <int>> cost(n, vector<int>(n, INT_MAX));

	FOR(i, 0, n) cin>>grid[i];

	int spx, spy, epx, epy;
	sf("%d %d %d %d", &spx, &spy, &epx, &epy);

	queue <ii> q;
	q.push({spx, spy});
	cost[spx][spy] = 0;

	while(!q.empty()){
		ii cur = q.front();
		for(int i = cur.ff-1; i>=0; i--){
			if(grid[i][cur.ss]=='X') break;
			if(cost[i][cur.ss]!=INT_MAX) continue;
			cost[i][cur.ss] = min(cost[i][cur.ss], cost[cur.ff][cur.ss] + 1);
			q.push({i, cur.ss});
		}

		for(int i = cur.ff+1; i<n; i++){
			if(grid[i][cur.ss]=='X') break;
			if(cost[i][cur.ss]!=INT_MAX) continue;
			cost[i][cur.ss] = min(cost[i][cur.ss], cost[cur.ff][cur.ss] + 1);
			q.push({i, cur.ss});
		}

		for(int i = cur.ss-1; i>=0; i--){
			if(grid[cur.ff][i]=='X') break;
			if(cost[cur.ff][i]!=INT_MAX) continue;
			cost[cur.ff][i] = min(cost[cur.ff][i], cost[cur.ff][cur.ss] + 1);
			q.push({cur.ff, i});
		}

		for(int i = cur.ss+1; i<n; i++){
			if(grid[cur.ff][i]=='X') break;
			if(cost[cur.ff][i]!=INT_MAX) continue;
			cost[cur.ff][i] = min(cost[cur.ff][i], cost[cur.ff][cur.ss] + 1);
			q.push({cur.ff, i});
		}

		q.pop();
	}

	printf("%d\n", cost[epx][epy]);


	
}