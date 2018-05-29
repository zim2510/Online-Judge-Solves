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
	Write();

	int nr, nn, i;
	int tc = 0;
	
	while(scanf("%d %d", &nr, &nn) && (nr || nn)){
		for(i = 1; i<=27; i++){
			if(nn*i>=nr) break;
		}
		printf("Case %d: ", ++tc);
		if(i>27) printf("impossible\n");
		else printf("%d\n", i-1);
	}

	return 0;
}