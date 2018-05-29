#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  50001

using namespace std;

int prime[MAX], nprime[5133], np = 0;
int phi[MAX];

void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[np++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[np++] = i;
	}
	//printf("%d\n", nprime[np-1]);
}

void phisiv()
{
	for(int i = 0; i<MAX; i++) phi[i] = i;
	for(int i = 0; i<np; i++){
		for(int x = nprime[i]; x<MAX; x+=nprime[i]){
			phi[x] -= phi[x]/nprime[i];
		}
	}
	for(int i = 1; i<MAX; i++) phi[i] = phi[i] + phi[i-1];
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	phisiv();
	int n;
	while(scanf("%d", &n) && n){
		printf("%d\n", phi[n]*2-1);
	}
	return 0;
}