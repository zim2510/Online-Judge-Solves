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


int L[35][35], R[35][35], U[35][35], D[35][35], M[35][35], P[35][35], MRK[35][35];
int r, c, mx;
int X, Y;
int lastx, lasty;


void PROCESS()
{
	FOR(i, 0, r) L[i][0] = M[i][0]?1:0; 
	FOR(i, 0, r){
		FOR(j, 1, c){
			L[i][j] = M[i][j]?L[i][j-1]+1:0;
		}
	}

	FOR(i, 0, c) U[0][i] = M[0][i]?1:0;
	FOR(i, 0, c){
		FOR(j, 1, r){
			U[j][i] = M[j][i]?U[j-1][i]+1:0;
		}
	}

	FOR(i, 0, r) R[i][c-1] = M[i][c-1]?1:0;
	FOR(i, 0, r){
		ROF(j, c-2, 0){
			R[i][j] = M[i][j]?R[i][j+1]+1:0;
		}
	}

	FOR(i, 0, c) D[r-1][i] = M[r-1][i]?1:0;
	FOR(i, 0, c){
		ROF(j, r-2, 0){
			D[j][i] = M[j][i]?D[j+1][i]+1:0;
		}
	}
}

void backtrack(int i, int j, int cnt)
{
	if(i==r-1){

		if(cnt==mx || mx==9){
			if(lastx>X){
				X = lastx;
				Y = lasty;
			}
			else if(lastx==X && lasty>Y){
				X = lastx;
				Y = lasty;
			}

		}

		else if(cnt>mx){
			mx = min(9, cnt);
			X = lastx;
			Y = lasty;
		}

		return;
	}

	if(j==c-1){
		backtrack(i+1, 1, cnt);
		return;
	}

	if(P[i][j] && !MRK[i-1][j] && !MRK[i][j-1]){
		MRK[i][j] = 1;
		lastx = i, lasty = j;
		backtrack(i, j+1, cnt+1);
		MRK[i][j] = 0;
	}

	backtrack(i, j+1, cnt);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	
	int tc;
	sf("%d", &tc);

	TC(i, 1, tc){
		MEM(M, 0);
		MEM(L, 0);
		MEM(R, 0);
		MEM(U, 0);
		MEM(D, 0);
		MEM(P, 0);
		MEM(MRK, 0);

		sf("%d %d", &r, &c);

		FOR(i, 0, r){
			FOR(j, 0, c){
				sf("%d", &M[i][j]);
			}
		}

		PROCESS();

		int cnt = 0;
		FOR(i, 0, r){
			FOR(j, 0, c){
				if(L[i][j]>=2 && R[i][j]>=2 && U[i][j]>=2 && D[i][j]>=2){
					P[i][j] = 1;
				} 
				else P[i][j] = 0;
			}
		}

		mx = 0;
		lastx = lasty = X = Y = 0;
		backtrack(1, 1, 0);

		printf("%d\n", max(2, min(9, mx)));
		printf("%d %d\n", X+1, Y+1);
	}
}
