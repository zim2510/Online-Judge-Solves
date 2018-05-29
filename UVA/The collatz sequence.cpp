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
	long long int a;
	int lmt, x;
	int t = 0;
	while(scanf("%lld %d", &a, &lmt)==2){
		++t;
		x = a;
		if(a<0 && lmt<0) break;
		int s = 0;
		while(a<=lmt){
			s++;
			if(a==1) break;
			if(a%2) a = 3*a + 1;
			else a /= 2;
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", t, x, lmt, s);
	}

	return 0;
}
