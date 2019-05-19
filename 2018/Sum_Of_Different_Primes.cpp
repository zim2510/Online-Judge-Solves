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

vector <int> primes(1, 2);
int opt[250][1200][1200];

int dp(int ci, int wrem, int nrem)
{
	if(!wrem && !nrem) return 1;
	if(wrem==0 || nrem<=0 || primes[ci]>nrem) return 0;
	if(opt[ci][wrem][nrem]!=-1) return opt[ci][wrem][nrem];
	return opt[ci][wrem][nrem] = dp(ci+1, wrem-1, nrem-primes[ci]) + dp(ci+1, wrem, nrem);
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	MEM(opt, -1);
	FOR(i, 3, 1250){
		int flag = 1;
		for(int j = 2; j*j<=i; j++){
			if(i%j==0){ flag = 0; break; }
		} if(flag) primes.pb(i);
	}
	int n, k;
	while(sf("%d %d", &n, &k) && (n || k)){
		cout<<dp(0, k, n)<<endl;
	}
}
