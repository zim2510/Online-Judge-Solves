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
#define MAX  10000001

LL vals[MAX];
int prime[MAX];
int nprime[MAX];
int tpow[25];

void siv()
{
	tpow[0] = 1;
	for(int i = 1; i<25; i++) tpow[i] = tpow[i-1]*2;
	
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}

	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]){
			int x = i*2;
			int t = 1;
			while(x<MAX){
				vals[x] = (i+1) * (tpow[t+1]-1) - 2*x;
				x *= 2;
				t++;
			}
		}
	}
	for(int i = 1; i<MAX; i++){
		vals[i] = vals[i] + vals[i-1];
	}
}

using namespace std;

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int n;
	while(scanf("%d", &n) && n){
		printf("%d %lld\n", n, vals[n]);
	}

	return 0;
}