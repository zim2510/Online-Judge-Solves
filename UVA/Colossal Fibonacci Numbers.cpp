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

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int bigmod(ULL n, ULL p, ULL mod)
{
	if(p==0) return 1;
	if(p%2) return ((n%mod)*bigmod(n, p-1, mod))%mod;
	LL x = bigmod(n, p/2, mod);
	return (x*x)%mod;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		ULL a, b, n;
		scanf("%llu %llu %llu", &a, &b, &n);
		if(n==1){
            printf("0\n");
            continue;
		}
		vector <int> fibs;
		fibs.pb(0);
		fibs.pb(1);
		int size = 0;
		while(1){
			fibs.pb((fibs[fibs.size()-1]+fibs[fibs.size()-2])%n);
			size++;
			if(fibs[fibs.size()-1]==1 && fibs[fibs.size()-2]==0){
				break;
			}
		}
		int x = bigmod(a, b, size);
		printf("%d\n", fibs[x]);
	}
}
