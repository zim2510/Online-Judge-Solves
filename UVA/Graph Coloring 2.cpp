#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))
#define sz(a) 			  int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int n, e, mx;
vector<int> sol(101);

void dfs(int x, vector<int> &clr, vector<vector<int> > &graph)
{
	if(x>n){
		int cnt = 0;
		for(int i = 1; i<clr.size(); i++) cnt += clr[i]>0?1:0;
		int idx = 0;
		if(cnt>mx) for(int i = 1; i<clr.size(); i++){
			mx = cnt;
			if(clr[i]>0) sol[idx++] = i;
		}
		return;
	}

	if(clr[x]<0) dfs(x+1, clr, graph);

	if(!clr[x]){
		clr[x]++;
		for(int i = 1; i<=n; i++){
			if(graph[x][i]) clr[i]--;
		}
		dfs(x+1, clr, graph);
		clr[x]--;
		for(int i = 1; i<=n; i++){
			if(graph[x][i]) clr[i]++;
		}
		dfs(x+1, clr, graph);
	}
}


int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		scanf("%d %d", &n, &e);
		vector<vector <int> > graph(n+1, vector<int>(n+1, 0));
		vector<int> clr(n+1, 0);
		for(int i = 0; i<e; i++){
			int s , e;
			scanf("%d %d", &s, &e);
			graph[s][e] = graph[e][s] = 1;
		}
		mx = 0;
		dfs(1, clr, graph);
		printf("%d\n", mx);
		printf("%d", sol[0]);
		for(int i = 1; i<mx; i++) printf(" %d", sol[i]);
		printf("\n");
		
	}
}
