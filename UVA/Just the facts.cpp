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
	//Read();
	//Write();
	int n;
	while(scanf("%d", &n)==1){
		int res = 1;
		for(int i = n; i>=2; i--){
			res *= i;
			while(res%10==0) res/=10;
			res = res%100000;
		}
		printf("%5d -> %d\n", n, res%10);
	}

	return 0;
}