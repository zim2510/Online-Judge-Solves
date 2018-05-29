#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

char grid[25][25];
int n;

void dfs(int i, int j)
{
	if(i>n || i<0) return;
	if(j>n || j<0) return;
	if(grid[i][j]=='1'){
		grid[i][j] = '0';
		dfs(i, j+1);
		dfs(i, j-1);
		dfs(i-1, j+1);
		dfs(i-1, j);
		dfs(i-1, j-1);
		dfs(i+1, j+1);
		dfs(i+1, j);
		dfs(i+1, j-1);
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc = 0;
	while(scanf("%d", &n)==1){
		int cnt = 0;
		for(int i = 0; i<n; i++){
			scanf(" %s", grid[i]);

		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(grid[i][j]=='1') {dfs(i, j); cnt++;}
			}
		}
		printf("Image number %d contains %d war eagles.\n", ++tc, cnt);
	}

	return 0;
}