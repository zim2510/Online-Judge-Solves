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

char grid[15][15];
int mark[15][15];
int mx;


void btrack(int r, int c, int cnt)
{
	if(cnt>mx) mx = cnt;
	if(r<0 || c<0 || r>14 || c>14) return;
	else if(grid[r][c]=='X') return;
	else if(mark[r][c]) return;
	else{
		mark[r][c] = 1;
		btrack(r-2,c-1, cnt+1);
		btrack(r-2,c+1, cnt+1);
		btrack(r-1,c-2, cnt+1);
		btrack(r-1,c+2, cnt+1);
		btrack(r+1,c-2, cnt+1);
		btrack(r+1,c+2, cnt+1);
		btrack(r+2,c-1, cnt+1);
		btrack(r+2,c+1, cnt+1);
		mark[r][c] = 0;
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int n, tc = 0;
	while(scanf("%d", &n) && n){
		MEM(grid, 'X');
		MEM(mark, 0);
		int total = 0;
		for(int i = 0; i<n; i++){
			int sp, ep;
			scanf("%d %d", &sp, &ep);
			total += ep;
			for(int j = 0; j<ep; j++){
				grid[i][sp+j] = '0';
			}
		}

		mx = 0;
		for(int i = 0; i<n; i++){
			int f = 0;
			for(int j = 0; j<10; j++){
				if(grid[i][j]=='0'){
					btrack(i, j, 0);
					f = 1;
					break;
				}
			}
			if(f) break;
		}
		printf("Case %d, %d %s can not be reached.\n", ++tc, total-mx, total-mx==1?"square":"squares");
	}

}