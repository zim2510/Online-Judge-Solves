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

LL fib[55];

void fibc()
{
	fib[0] = fib[1] = 1;
	for(int i = 2; i<53; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	fibc();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int n;
		scanf("%d", &n);
		printf("Scenario #%d:\n", i);
		printf("%lld\n\n", fib[n+1]);
	}
	return 0;
}