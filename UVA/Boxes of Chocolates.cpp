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
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int f, b;
		int ans = 0, rem, k;
		scanf("%d %d", &f, &b);
		for(int i = 0; i<b; i++){
			k, rem = 1;
			scanf("%d", &k);
			for(int i = 0; i<k; i++){
				int x;
				scanf("%d", &x);
				rem = (rem*x)%f;
			}
			ans += rem;
		}
		printf("%d\n", ans%f);
	}

	return 0;
}