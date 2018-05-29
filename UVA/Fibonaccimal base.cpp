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

int f[50];

void fibc()
{
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i<40; i++){
		f[i] = f[i-1] + f[i-2];
		//printf("%d\n", f[i]);
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	fibc();
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		printf("%d = ", n);
		int pos = upper_bound(f, f+40, n) - f - 1;
		for(int i = pos; i>0; i--){
			if(n>=f[i]){
				printf("1");
				n -= f[i];
			}
			else printf("0");
		} printf(" (fib)\n");
	}

	return 0;
}