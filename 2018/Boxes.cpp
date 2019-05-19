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

int opt[3005][3005];
int mark[3005][3005];
int n, check = 0;
int w[3005], m[3005];

int dp(int pos, int mxload)
{
    if(pos==n) return 0;
    if(mark[pos][mxload]==check) return opt[pos][mxload];
    mark[pos][mxload] = check;
    opt[pos][mxload] = dp(pos+1, mxload);
    if(w[pos]<=mxload){
        opt[pos][mxload] = max(opt[pos][mxload], 1 + dp(pos+1, min(mxload-w[pos], m[pos])));
    }
    return opt[pos][mxload];
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();;
    while(scanf("%d", &n) && n){
        check++;
        FOR(i, 0, n){
            sf("%d %d", &w[i], &m[i]);
        }
        int ans = 0;

        FOR(i, 0, n){
            ans = max(ans, 1+ dp(i+1, m[i]));
        }

        cout<<ans<<endl;
    }
}
