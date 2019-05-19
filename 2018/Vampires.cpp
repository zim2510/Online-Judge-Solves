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

double opt[30][1005];
bool chk[30][1005];

int m, d;

double dp(int e1, int e2, int depth)
{
	if(depth==0) return 0;
	if(e1<=0) return 0;
	if(e2<=0) return 1;
	if(chk[e1][depth]) return opt[e1][depth];
    chk[e1][depth] = 1;
    opt[e1][depth] = (m/6.0)*dp(e1+d, e2-d, depth-1) + (1-m/6.0)*dp(e1-d, e2+d, depth-1);
    return opt[e1][depth];
}

int main(int argc, char const *argv[])
{
	//Read();
    //ZWrite();
    int e1, e2;
    while(sf("%d%d%d%d", &e1, &e2, &m, &d) && (e1+e2+m+d)){
    	MEM(chk, 0);
    	printf("%0.1lf\n", dp(e1, e2, 1000)*100);
    }
    
}
