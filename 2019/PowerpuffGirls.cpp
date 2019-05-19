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

char grid[25][25];
int  mark[25][25], r, c;

int BFS(int sx, int sy)
{
	queue <int> X, Y;

	X.push(sx);
	Y.push(sy);

	mark[sx][sy] = 0;

	while(!X.empty()){
		int x = X.front(), y = Y.front();
		X.pop(), Y.pop();

		if(grid[x][y]=='h'){
			int ret = mark[x][y];
			MEM(mark, -1);
			return ret;
		}

		if(valid(x, 0, r-1) && valid(y+1, 0, c-1) && mark[x][y+1]==-1 && grid[x][y]!='#' && grid[x][y]!='m'){
			X.push(x);
			Y.push(y+1);
			mark[x][y+1] = mark[x][y] + 1;
		}

		if(valid(x, 0, r-1) && valid(y-1, 0, c-1) && mark[x][y-1]==-1 && grid[x][y]!='#' && grid[x][y]!='m'){
			X.push(x);
			Y.push(y-1);
			mark[x][y-1] = mark[x][y] + 1;
		}

		if(valid(x+1, 0, r-1) && valid(y, 0, c-1) && mark[x+1][y]==-1 && grid[x][y]!='#' && grid[x][y]!='m'){
			X.push(x+1);
			Y.push(y);
			mark[x+1][y] = mark[x][y] + 1;
		}

		if(valid(x-1, 0, r-1) && valid(y, 0, c-1) && mark[x-1][y]==-1 && grid[x][y]!='#' && grid[x][y]!='m'){
			X.push(x-1);
			Y.push(y);
			mark[x-1][y] = mark[x][y] + 1;
		}
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
	MEM(mark, -1);

	TC(i, 1, tc){
		sf("%d %d", &r, &c);
		int ax, ay, bx, by, cx, cy;

		FOR(i, 0, r){
			FOR(j, 0, c){
				sf(" %c", &grid[i][j]);
				if(grid[i][j]=='a') ax = i, ay = j;
				if(grid[i][j]=='b') bx = i, by = j;
				if(grid[i][j]=='c') cx = i, cy = j;
			}
		}

		int ans = -1;
		ans = max(ans, BFS(ax, ay));
		ans = max(ans, BFS(bx, by));
		ans = max(ans, BFS(cx, cy));

		printf("Case %d: %d\n", i, ans);
	}
}
