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

int grid[100][100];
int flag = 0;
int opt[100][100][100];
int n, k;

int dp(int x, int y, int neg)
{
	if(opt[x][y][neg]!=-1) return 0;
	if(!valid(x, 0, n-1) || !valid(y, 0, n-1)) return -100000000;
	if(neg==5 && grid[x][y]<0) return -100000000;

	if(x==n-1 && y==n-1) {flag = 1; return grid[x][y];}

	else{
		opt[x][y][neg] = grid[x][y];
	 	opt[x][y][neg] += max3(dp(x, y+1, neg+(grid[x][y]<0)), 
	 						   dp(x, y-1, neg+(grid[x][y]<0)), 
	 						   dp(x+1, y, neg+(grid[x][y]<0))
	 						  );
		cout<<x<<" "<<y<<" "<<neg<<" "<<opt[x][y][neg]<<endl;
		return opt[x][y][neg];
	}


}

int main(int argc, char const *argv[])
{
	Read();
    Write();
    
    scanf("%d", &n, &k);

    FOR(i, 0, n){
    	FOR(j, 0, n){
    		scanf("%d", &grid[i][j]);
    	}
    }
    MEM(opt, -1);
    cout<<dp(0, 0, 0);
}
