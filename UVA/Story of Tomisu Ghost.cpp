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
#define MAX               100000
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

vector<int> prime(MAX/2), nprime;
void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i>>1]) for(int x = i*i; x<MAX; x+=2*i) prime[x>>1] = 1;
	}
	nprime.pb(2);
	for(int i = 1; i<(MAX>>1); i++){
		if(!prime[i]) nprime.pb((i<<1)+1);
	}
}

vector <int> factorized, pwr;
void factorize(int n, int mn)
{
	factorized.clear();
	pwr.clear();
	for(int i = 0; i<nprime.size() && nprime[i]<=n; i++){
		int cnt = 0;
		int x = n;
		while(x){
			cnt += x/nprime[i];
			x /= nprime[i];
		}
		if(cnt>=mn){
			factorized.pb(nprime[i]);
			pwr.pb(cnt);
		}
		else return;
	}
}

LL bigmod(LL n, LL p, LL m)
{
	if(!p) return 1;
	if(p%2) return ((n%m)*bigmod(n, p-1, m))%m;
	LL x = bigmod(n, p/2, m);
	return (x*x)%m;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		int n, zeroes;
		scanf("%d %d", &n, &zeroes);
		factorize(n, zeroes);
		LL ans = 1;
		FOR(i, 0, factorized.size()){
			//cout<<factorized[i]<<" "<<pwr[i]<<endl;
			ans *= bigmod(factorized[i], pwr[i]/zeroes, 10000019);
			ans %= 10000019;
		}
		printf("Case %d: %lld\n", i, ans==1?-1:ans);
	}
	
}