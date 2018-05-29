#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, tc)		  for(int i = 1; i<=tc; i++)
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
	Write();
	int tc;
	scanf("%d", &tc);

	TC(i, tc){
		double n;
		scanf("%lf", &n);
		printf("Case %d:", i);
		for(int i = 1; i<n; i--){
			double x = (double)i/sqrt(n-i);
			if(x==(int) x) printf(" %d\n", i);
		}
	}
	return 0;
}