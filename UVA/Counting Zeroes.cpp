#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(LL i = a; a<=b; i++)
#define FOR(i, a, b)      for(LL i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int prime[MAX], nprime[664580], np = 0;
vector <LL> pfactors;
vector <LL> factors;
int fcnt[664580];

void makefactors(int n, LL factor, int sz)
{
	if(n==sz && factor>1) factors.pb(factor);
	else if(n<sz){
		makefactors(n+1, factor, sz);
		for(int i = 0; i<fcnt[n]; i++){
			factor *= pfactors[n];
			makefactors(n+1, factor, sz);
		}
	}
}

void siv()
{
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]){
			for(int x = i*i; x<MAX; x += 2*i) prime[x] = 1;
		}
	}
	nprime[np++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[np++] = i;
	}
}

void factorize(LL n)
{
	int lmt = sqrt(n), sz = 0;
	for(int i = 0; nprime[i]<=lmt; i++){
		if(n%nprime[i]==0){
			pfactors.pb(nprime[i]);
			fcnt[sz] = 0;
			while(n%nprime[i]==0){
				fcnt[sz]++;
				n /= nprime[i];
			}
			sz++;
		}
	}
	if(n>1){
		pfactors.pb(n);
		fcnt[sz]++;
	}
}


int main()
{
	//Read();
	//Write();
	siv();
	LL n;
	while(scanf("%lld", &n) && n){
		pfactors.clear();
		factors.clear();
		factorize(n);
		makefactors(0, 1, pfactors.size());
		int zeroes = 0;
		int sz = factors.size();
		for(int i = 0; i<sz; i++){
			LL x = n;
			while(x%factors[i]==0){
				zeroes++;
				x /= factors[i];
			}
		}
		printf("%lld %d\n", n, zeroes);
	}
	return 0;
}
