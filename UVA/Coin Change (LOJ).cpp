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

int coins[55], amount[55];
int opt[1005][55], n;

int dp(int ci, int val)
{
	if(ci==n && val==0) return 1;
	else if(ci==n) return 0;
	if(opt[val][ci]!=-1) return opt[val][ci];
	opt[val][ci] = 0;
	for(int i = 0; i<=amount[ci]; i++){
		if(coins[ci]*i>val) break;
		opt[val][ci] += dp(ci+1, val-coins[ci]*i);
		opt[val][ci] %= 100000007;
	}
	return opt[val][ci];
}


int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		int val;
		scanf("%d %d", &n, &val);
		for(int i = 0; i<n; i++) scanf("%d", &coins[i]);
		for(int i = 0; i<n; i++) scanf("%d", &amount[i]);
		MEM(opt, -1);
		printf("Case %d: %d\n", i, dp(0, val));
	}
}