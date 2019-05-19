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

LL sum[200];
LL coin[200];
LL opt[5][200][200][5];

LL dp(int player, int start, int end, int open)
{
	if(start==end) return opt[player][start][end][open] = coin[start];

	if(opt[player][start][end][open]!=-1) return opt[player][start][end][open];

	LL x, y, z, s, ans;

	if(open==2){
		x = coin[start] + sum[end] - sum[start]  -  dp(!player, start+1, end, 2);
		y = coin[end] + sum[end-1] - sum[start-1] - dp(!player, start, end-1, 2);

		z = coin[start] + dp(player, start+1, end, 0);
		s = coin[end] + dp(player, start, end-1, 1);

		ans = max3(x, y, max(z, s));
	}

	if(open==0){
		x = coin[start] + sum[end] - sum[start]  - dp(!player, start+1, end, 2);
		y = coin[start] + dp(player, start+1, end, 0);
		ans = max(x, y);
	}

	if(open==1){
		x = coin[end] + sum[end-1] - sum[start-1] - dp(!player, start, end-1, 2);
		y = coin[end] + dp(player, start, end-1, 1);
		ans = max(x, y);
	}
	return opt[player][start][end][open] = ans;

	
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int n;
    while(scanf("%d", &n) && n){
    	TC(i, 1, n){
    		scanf("%lld", &coin[i]);
    		sum[i] = sum[i-1] + coin[i];
    	}
    	MEM(opt, -1);
    	LL p1 = dp(0, 1, n, 2);
    	LL p2 = sum[n] - p1;
    	printf("%lld\n", (p1-p2));
    }
    
}
