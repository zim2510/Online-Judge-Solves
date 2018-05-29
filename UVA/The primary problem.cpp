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
#define MAX  1000000

using namespace std;

int prime[MAX];
int nprime[78498];

void siv()
{
	int n = 0;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}

	nprime[n++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[n++] = i;
	}
}

int main(int argc, char const *argv[])
{
	// Read();
	// Write();
	siv();
	int n;
	while(scanf("%d", &n) && n){
		printf("%d:\n", n);
		if(n%2){
			if(!prime[n-2]) printf("%d+%d\n", 2, n-2)
			else printf("NO WAY!"\n);
			continue;
		}
		for(int i = 0; i<78498 && nprime[i]<=n/2; i++){
			if(!prime[n-nprime[i]]){
				printf("%d+%d\n", nprime[i], n-nprime[i]);
				break;
			}
		}
	}

	return 0;
}