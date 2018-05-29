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
#define MAX               65536
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
bool prime[MAX];
int nprime[6545], nprimes = 0;
void siv()
{
	for(int i = 3; i*i<=MAX; i+=2){
		if(!prime[i/2]){
			for(int x = i*i; x<=MAX; x+=2*i){
				prime[x/2] = 1;
			}
		}
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<=MAX; i+=2){
		if(!prime[i/2]) nprime[nprimes++] = i;
	}
}


vector <LL> factor;
vector <int> pwr;
void factorize(LL n)
{
	factor.clear();
	pwr.clear();
	for(int i = 0; i<nprimes && i*i<=n; i++){
		if(n%nprime[i]==0){
			factor.pb(nprime[i]);
			int cnt = 0;
			while(n%nprime[i]==0){
				cnt++;
				n /= nprime[i];
			}
			pwr.pb(cnt);
		}
	}
	if(n!=1){
		factor.pb(n);
		pwr.pb(1);
	}
}
int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	LL n;
	while(scanf("%lld", &n) && n){
		factorize(abs(n));
		int res = pwr[0];
		for(int i = 1; i<pwr.size(); i++){
			res = __gcd(res, pwr[i]);
		}
		if(n>0) printf("%d\n", res);
		if(n<0){
			if(res%2) printf("%d\n", res);
			else{
				while(res%2==0) res /= 2;
				printf("%d\n", res);
			}
		}

	}
	
}