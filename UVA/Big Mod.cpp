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
#define MAX  50000

using namespace std;


int bigmod(int base, int power, int mod)
{
	if(power==0) return 1;
	if(power%2) return (base%mod * bigmod(base, power-1, mod))%mod;
	int x = bigmod(base, power/2, mod);
	return (x*x)%mod;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int b, p, m;
	while(scanf("%d %d %d", &b, &p, &m)==3){

		printf("%d\n", bigmod(b, p, m));
	}
}
