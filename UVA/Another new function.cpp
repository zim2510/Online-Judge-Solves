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
#define MAX  2000001

using namespace std;

int prime[MAX], nprime[148934], np = 0;
int phi[MAX], depth[MAX];

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
}

void phisiv()
{
	for(int i = 0; i<MAX; i++) phi[i] = i;
	for(int i = 0; i<np; i++){
		for(int x = nprime[i]; x<MAX; x+=nprime[i]){
			phi[x] -= phi[x]/nprime[i];
		}
	}
}

void cdepth()
{
	depth[0] = 0;
	depth[1] = 0;
	for(int i = 2; i<MAX; i++){
		depth[i] = 1 + depth[phi[i]];
	}
	//for(int i = 0; i<=10; i++) printf("%d\n", depth[i]);
	for(int i = 2; i<MAX; i++) depth[i] = depth[i] + depth[i-1];
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	phisiv();
	cdepth();
	int tc;
	scanf("%d", &tc);
	//for(int i = 0; i<=10; i++) printf("%d\n", depth[i]);
	for(int i = 1; i<=tc; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", depth[e]-depth[s-1]);
	}

	return 0;
}
