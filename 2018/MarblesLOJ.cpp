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

double opt[505][505];
int mark[505][505];

double dp(int r, int b)
{
	if(r==0) return 1;
	if(b<=0) return 0;
	if(mark[r][b]) return opt[r][b];

	mark[r][b] = 1;

	double pro = (r/double(r+b))*dp(r-1, b-1) + (b/double(r+b))*dp(r, b-2);

	return opt[r][b] = pro;
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    
    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	int r, b;
    	scanf("%d %d", &r, &b);
    	printf("Case %d: %0.6lf\n", i, dp(r, b));
    }
}
