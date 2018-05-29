#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
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

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; ++i)
	{
		int tbl[210][210];
		MEM(tbl, 0);
		int sz;
		scanf("%d", &sz);
		int in[210][210];
		for(int i = 1; i<=sz; i++){
			for(int j = 1; j<=i; j++){
				scanf("%d", &in[i][j]);
			}
		}

		for(int i = sz+1; i<2*sz; i++){
			for(int j = 1; j<=(2*sz-i); j++){
				scanf("%d", &in[i][j]);
			}
		}

		for(int i = 2*sz-1; i>=1; i--){
			if(i>=sz) for(int j = 1; j<=(2*sz-i); j++){
				tbl[i][j] = in[i][j] + max(tbl[i+1][j], tbl[i+1][j-1]);
			}
			else for(int j = 1; j<=(2*sz-i); j++){
				tbl[i][j] = in[i][j] + max(tbl[i+1][j], tbl[i+1][j+1]);
			}
		}
		printf("Case %d: %d\n", i, tbl[1][1]);
	}

}