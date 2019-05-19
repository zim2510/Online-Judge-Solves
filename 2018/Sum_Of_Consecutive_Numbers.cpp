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
#define MAX               10000000
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

vector <int> prime(MAX/2), nprime;
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

vector <LL> factorized, pwr;
void factorize(LL n)
{
	factorized.clear();
	pwr.clear();
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

vector <LL> divs;
void finddivs(LL x, int ci)
{
	if(ci==factorized.size()) { divs.pb(x); return; }

	finddivs(x, ci+1);

	for(int i = 0; i<pwr[ci]; i++){
		x *= factorized[ci];
		finddivs(x, ci+1);
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		LL n;
		scanf("%lld", &n);
		n *= 2;
		factorize(n);
		divs.clear();
		finddivs(1, 0);

		sort(divs.begin(), divs.end());
		unique(divs.begin(), divs.end());
		LL cnt = 0;
		for(int i = 1; i<divs.size()-1; i++){
			//if(divs[i]*divs[i]>n) break;
			if(divs[i]%2 != ((n)/divs[i])%2) cnt++;
		}
		printf("Case %d: %lld\n", i, cnt/2);
	}
}

