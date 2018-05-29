#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int prime[MAX], nprime[MAX/2];
int nprimes;

void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[nprimes++] = i;
	}
	//printf("%d\n", nprimes);
}

LL factorize(LL n)
{
	LL mx = 0, cnt = 0;
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			cnt++;
			mx = nprime[i];
			while(n%nprime[i]==0) n /= nprime[i];
		}
	}
	if(cnt==n) return 0;
	return max(mx, n);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	LL n;
	while(scanf("%lld", &n) && n){
		LL mx = factorize(n);
		if(mx!=n && mx!=0) printf("%lld\n", mx);
		else printf("-1\n");
	}

	return 0;
}