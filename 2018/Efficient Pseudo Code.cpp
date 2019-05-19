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
#define MOD 			  1000000007

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

vector <int> prime, nprime;
void siv(int N)
{
	prime.resize(N/2, 0);
	for(int i = 3; i*i<N; i+=2){
		if(!prime[i/2]){
			for(int x = i*i; x<N; x += 2*i){
				prime[x/2] = 1;
			}
		}
	}
	nprime.pb(2);
	FOR(i, 1, N/2){
		if(!prime[i]) nprime.pb(i*2+1);
	}
}

vector <int> factorized, pwr;
void factorize(int n)
{
	for(int i = 0; i<nprime.size() && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			factorized.pb(nprime[i]);
			int cnt = 0;
			while(n%nprime[i]==0){
				n /= nprime[i];
				cnt++;
			}
			pwr.pb(cnt);
		}
	}
	if(n!=1){
		factorized.pb(n);
		pwr.pb(1);
	}
}

LL bigmod(LL n, LL p, LL m)
{
	if(!p) return 1;
	if(p&1) return (n*bigmod(n, p-1, m))%m;
	LL x = bigmod(n, p/2, m);
	return (x*x)%m;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv(10000000);


	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		factorized.clear();
		pwr.clear();
		LL n, m;
		scanf("%lld %lld", &n, &m);
		factorize(n);
		LL res = 1;
		FOR(i, 0, factorized.size()){
			LL temp = ((bigmod(factorized[i], pwr[i]*m+1, MOD) - 1) * bigmod(factorized[i]-1, MOD-2, MOD))%MOD;
			res = (res*temp)%MOD;
		}
		printf("Case %d: %lld\n", i, (res+MOD)%MOD);
	}
}