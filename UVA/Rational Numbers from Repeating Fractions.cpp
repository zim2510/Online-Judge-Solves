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

int main(int argc, char const *argv[])
{
	Read();
	//Write();
	int j, tc = 0;
	while(scanf("%d", &j) && j>-1){
		char x[100];
		scanf(" %s", x);
		int sz = strlen(x);
		int sum1 = 0, sum2 = 0;
		int x1 = 1, x2 = 1;
		for(int i = 2; i<sz; i++){
			sum1 = sum1*10+x[i]-'0';
			x1 *= 10;
		}

		if(j) for(int i = 2; i<sz-j; i++){
			sum2 = sum2*10 + x[i] - '0';
			x2 *= 10;
		}
		printf("HERE\n");
		sum1 -= sum2;
		x1 -= x2;
		printf("%d %d\n", sum1, x1);
		int g = __gcd(sum1, x1);

		printf("Case %d: %d/%d\n", ++tc, sum1/g, x1/g);
	}

	return 0;
}
