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

int mark[25][25];
char grid[25][25];
int r, c;
int cnt;

void dfs(int x, int y)
{
	if(!valid(x, 0, r-1)) return;
	if(!valid(y, 0, c-1)) return;
	if(grid[x][y]=='#') return;
	if(mark[x][y]) return;

	mark[x][y]++;
	cnt++;

	dfs(x, y+1);
	dfs(x, y-1);
	dfs(x+1, y);
	dfs(x-1, y);
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
		int startx, starty;
		sf("%d %d", &c, &r);
		FOR(i, 0, r){
			FOR(j, 0, c){
				sf(" %c", &grid[i][j]);
				if(grid[i][j]=='@'){
					startx = i;
					starty = j;
				}
			}
		}
		cnt = 0;
		MEM(mark, 0);
		dfs(startx, starty);
		printf("Case %d: %d\n", i, cnt);
	}
}
