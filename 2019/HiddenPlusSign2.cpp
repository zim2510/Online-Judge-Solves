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

bool check(int N,int pos)	{ return (bool)(N & (1<<pos)); }
int sset(int N,int pos)		{	return N=N | (1<<pos);	   }


int M[35][35], P[35][35];
int r, c, mx;
int X, Y;
int lastx, lasty;

int calc(int x, int y, int dx, int dy)
{
	int cnt = 0;
	while(valid(x, 0, r-1) && valid(y, 0, c-1) && M[x][y]){
		x += dx;
		y += dy;
		cnt++;
	}
	return cnt;
}

void backtrack(int x, int y, int cnt)
{

	if(x==r){
		int pos = 1;
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				if(M[i][j]) {pos = 0; break;}
			} if(!pos) break;
		}

		if(!pos) return;

		if(cnt==mx){
			if(lastx>X){
				X = lastx;
				Y = lasty;
			}
			else if(lastx==X && lasty>Y){
				Y = lasty;
			}
		}

		if(cnt>mx){
			mx = cnt;
			X = lastx;
			Y = lasty;
		}

		return;
	}

	if(y==c){
		backtrack(x+1, 1, cnt);
		return;
	}

	backtrack(x, y+1, cnt);

	if(P[x][y]==1){

		int lmt = INT_MAX;
		
		lmt = min3(lmt, calc(x, y, -1, 0), calc(x, y, +1, 0));
		lmt = min3(lmt, calc(x, y, 0, -1), calc(x, y, 0, +1));

		
		if(lmt>1){

			M[x][y] = 0;
			for(int i = 1; i<lmt; i++){
				M[x+i][y]--;
				M[x-i][y]--;
				M[x][y+i]--;
				M[x][y-i]--;
			}

			lastx = x, lasty = y;
			backtrack(x, y+1, cnt+1);

			M[x][y] = 1;
			for(int i = 1; i<lmt; i++){
				M[x+i][y]++;
				M[x-i][y]++;
				M[x][y+i]++;
				M[x][y-i]++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	
	int tc;
	sf("%d", &tc);

	TC(i, 1, tc){
		MEM(M, 0);
		mx = 0;
		lastx = lasty = X = Y = 0;

		sf("%d %d", &r, &c);

		FOR(i, 0, r){
			FOR(j, 0, c){
				sf("%d", &M[i][j]);
				P[i][j] = M[i][j];
			}
		}

		
		backtrack(1, 1, 0);

		printf("%d\n", mx);
		printf("%d %d\n", X+1, Y+1);
	}

}
