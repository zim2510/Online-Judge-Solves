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
#define MAX  10000000

using namespace std;

int main(int argc, char const *argv[])
{
	Read();
	Write();

	LL n, k;
	while(scanf("%lld %lld", &n, &k)==2){
		if(n-k>k) k = n-k;
		double res = 0;
		for(int i = 1; i<=n-k; i++){
			//printf("%d %d\n", i, k+i);
			res += log10(k+i) - log10(i);
		}
		printf("%d\n", (int)res+1);
	}

	return 0;
}