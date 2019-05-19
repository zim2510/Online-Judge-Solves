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

vector <int> divs;
LL opt[50][50];
LL gg;

LL dp(int n, int k)
{
	if(k==0) return 1;
	if(opt[n][k]!=-1) return opt[n][k];

	LL ans = n*n;
   
	for(int i = 1; i<=gg; i++){
		if(!divs[i] && ans%i==0){
			divs[i] = 1;
			ans /= i;
		}
	}

	ans *= dp(n-1, k-1);
	return opt[n][k] = ans;
}

int main(int argc, char const *argv[])
{
	Read();
   Write();
   	int tc;
   	sf("%d", &tc);

   	TC(i, 1, tc){
   		int n, k;
   		sf("%d %d", &n, &k);
   		printf("Case %d: ", i);
   		if(n<k) printf("0\n");
   		else{
   			gg = k;
   			divs.clear();
   			divs.resize(k+1, 0);
   			MEM(opt, -1);
   			printf("%lld\n", dp(n, k));
   		}
   	}
}
