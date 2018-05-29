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

char in[45][45];
int mark[45][45];
int mn = INT_MAX/2, mx, my, mxn;

void dfs(int x, int y, int pwr)
{
	if(x<0 || y<0 || x>=mx || y>=my || in[x][y] == '#' || mark[x][y] || pwr>mxn/2) return;
	if(in[x][y]=='x'){
		if(mn>pwr) mn = pwr;
	}
	if(in[x][y]=='.'){
		mark[x][y] = 1;
		dfs(x, y+1, pwr);
		dfs(x, y-1, pwr);
		dfs(x+1, y, pwr);
		dfs(x-1, y, pwr);
	}
	if(in[x][y]=='s'){
		mark[x][y] = 1;
		dfs(x, y+1, pwr+1);
		dfs(x, y-1, pwr+1);
		dfs(x+1, y, pwr+1);
		dfs(x-1, y, pwr+1);
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int x, y, n;
	scanf("%d %d %d", &x, &y, &n);
	mx = x;
	my = y;
	mxn = n;
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			scanf(" %c", &in[i][j]);
		}
	}

	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			if(in[i][j]=='@'){
				MEM(mark, 0);
				dfs(i, j+1, 0);
				dfs(i+1, j, 0);
				dfs(i-1, j, 0);
				dfs(i, j-1, 0);
			}
		}
	}
	if(mn*2<=n) printf("SUCCESS\n");
	else printf("IMPOSSIBLE\n");
	


}