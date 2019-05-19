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

vector <int> t;
vector <vector <vector <int> > >  opt;
int n, mx, d;

int dp(int ci, int rem, int count)
{
	//cout<<ci<<" "<<rem<<" "<<count<<endl;
	//cout<<opt[ci][rem][count]<<endl;
	if(ci==n || count==d) return 0;
	if(opt[ci][rem][count]!=-1) return opt[ci][rem][count];
	
	int x = 0;

	x = dp(ci+1, rem, count);
	x = max(x, dp(ci, mx, count+1));

	if(rem>=t[ci]){
		x = max(x, 1 + dp(ci+1, rem-t[ci], count));
	}

	return opt[ci][rem][count] = x;
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int tc;
    scanf("%d", &tc);

    FOR(i, 0, tc){
    	if(i) printf("\n");
    	scanf("%d %d %d", &n, &mx, &d);
    	t.clear();
    	t.resize(n);
    	opt.clear();
    	opt.resize(n+5, vector <vector <int>> (mx+5, vector <int> (d+5, -1)));
    	FOR(i, 0, n){
    		sf(" %d%*c", &t[i]);
    	}
    	int ans = 0;
    	//printf("HERE %d\n\n", opt[0][mx][0]);
    	ans += dp(0, mx, 0);
    	printf("%d\n", ans);
    }
    
}
