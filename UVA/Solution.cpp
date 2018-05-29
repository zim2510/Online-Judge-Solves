#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  1000000

using namespace std;

int prime[MAX];
int nprime[78498];

void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]){
			for(int x = i*i; x<MAX; x+=2*i){
				prime[x] = 1;
			}
		}
	}
	int n = 0;
	nprime[n++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[n++] = i;
	}
}

vector <int> index;
vector <int> mfac;

int findcnt(int n, int x)
{
	int cnt = 0;
	while(n){
		cnt += n/x;
		n /= x;
	}
	return cnt;
}

void factorize(int n){
	for(int i = 0; nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			index.pb(i);
			int cnt = 0;
			while(n%nprime[i]==0){
				cnt++;
				n /= nprime[i];
			}
			mfac.pb(cnt);
		}
	}
	if(n!=1){
		index.pb(lower_bound(nprime, nprime+78498, n) - nprime);
		mfac.pb(1);
	}
}

LL BM(int n, int p, int m){
	if(p==0) return 1;
	LL x = BM(n, p/2, m);
	if(p%2==0){
		return (LL) (x*x)%m;
	}
	else return (LL) (n * BM(n, p-1, m))%m;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int n, m;
		scanf("%d %d", &n, &m);
		mfac.clear();
		index.clear();
		factorize(m);
		int mn = 100000000;
		for(int i = 0; i<mfac.size(); i++){
			int t = findcnt(n, nprime[index[i]])/mfac[i];
			if(mn>t) mn = t;
		}
		int r = BM(m, mn, 10000007);
		printf("%d\n", r);
	}
		

	return 0;
}