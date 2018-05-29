#include <bits/stdc++.h>

#define Read() freopen("in.txt", "r", stdin)
#define Write() freopen("out.txt", "w", stdout)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define REP(i, a, b) for(int i = a; a<=b; i++)
#define FOR(i, a, b) for(int i = a; a<b; i++)
#define MEM(a, x) memset(a, x, sizeof(a))

#define pb push_back
#define LL long long
#define ULL unsigned long long
#define MAX 50000

int prime[MAX], primes[5135];

using namespace std;

void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i){
			prime[x] = 1;
		}
	}
	int x = 0;
	primes[x++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) primes[x++] = i;
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int n, m;
	int fcnt[50000];
	vector<int> factors;

	while(scanf("%d %d", &n, &m)==2){
		factors.clear();
		int pos = 1;
		if(n>m) {printf("%d divides %d!\n", m, n); continue;}
		int x = m;
		int lmt = sqrt(m);
		for(int i = 0; primes[i]<=lmt; i++){
			if(m%primes[i]==0){
				factors.pb(primes[i]);
				int sz = factors.size() - 1;
				fcnt[sz] = 0;
				while(m%primes[i]==0){
					fcnt[sz]++;
					m /= primes[i];
				}
			}
		}
		int sz = factors.size();
		fcnt[sz] = 0;
		if(m!=1){factors.pb(m), fcnt[sz]++;}
		sz = factors.size();
		for(int i = 0; i<sz; i++){
			int cnt = 0, d = factors[i], val = n;
			while(val)	cnt += val/d, val = val/d;
			if(cnt<fcnt[i]) pos = 0;
		}
		if(pos) printf("%d divides %d!\n", x, n);
		else printf("%d does not divide %d!\n", x, n);
	}
	return 0;
}

