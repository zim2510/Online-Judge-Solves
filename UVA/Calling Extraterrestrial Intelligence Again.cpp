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

int prime[MAX], nprime[95950];
int nprimes = 0;
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
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	printf("%d\n", prime[241]);
	int m, a, b;
	while(scanf("%d %d %d", &m, &a, &b) && (a||b||m)){
		int best = 0, w, h;
		int g = __gcd(a,b);
		a = a/g;
		b = b/g;
		int ilo = (m/(a+b))*a;
		//int ilop = lower_bound(nprime, nprime+nprimes, ilo) - nprime;
		for(int i = 0; nprime[i]*nprime[i]<=m; i++){
			int jmx = (nprime[i]*b)/a;
			//printf("HL: %d %d %d %d\n", nprime[i], jmx, a, b);
			int jmxp = upper_bound(nprime, nprime+nprimes, jmx) - nprime - 1;
			for(int j = 0; j<=jmxp; j++){
				if(nprime[i]*nprime[j]>m) break;
				if(nprime[i]*nprime[j]>best){
					best = nprime[i]*nprime[j];
					w = nprime[i];
					h = nprime[j];
				}
			}
		}
		printf("%d %d\n", w, h);

	}

	return 0;
}