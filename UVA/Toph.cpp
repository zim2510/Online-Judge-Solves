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

int n, e;

void dfs(int np, int c, vector<int> &clr, vector<vector<int> > &graph)
{
    //printf("%d %d %d\n", n, clr[n], c);
	if(clr[np]>=0) return;
	else{
		clr[np] = c;
		printf("Coloring %s\n", !c?"White":"Black");
		for(int i = 1; i<=n; i++){
			if(graph[np][i]) printf("From %d to %d\n", np, i);
			if(graph[np][i]) dfs(i, !c, clr, graph);
		}
	}
	printf("Getting back\n");
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
		vector<int> clr(n+1, -1);
		for(int i = 0; i<e; i++){
			int s , e;
			scanf("%d %d", &s, &e);
			graph[s][e] = graph[e][s] = 1;
		}
		dfs(1, 1, clr, graph);
		int fb = 0;
		for(int i = 1; i<=n; i++){
			if(clr[i]) fb++;
		}
		vector<int> clr2(n+1, -1);
		dfs(1, 0, clr2, graph);
		int fw = 0;
		for(int i = 1; i<=n; i++){
			if(clr2[i]) fw++;
		}
		printf("%d\n", max(fb, fw));
		if(fb>fw){
			for(int i = 1; i<clr.size(); i++){
				if(clr[i]) printf("%d", i);
				if(clr[i] && i<clr.size()-1) printf(" ");
			}
			printf("\n");
		}
		else{
			for(int i = 1; i<clr.size(); i++){
				if(clr2[i]) printf("%d", i);
				if(clr2[i] && i<clr.size()-1) printf(" ");
			}
			printf("\n");
		}
	}
}
