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
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int ns, nc;
		int cs[100000];
		scanf("%d %d", &ns, &nc);

		for(int i = 0; i<ns; i++){
			scanf("%d", &cs[i]);
		}

		sort(cs, cs+ns);

		int hi = cs[ns-1] - cs[0];
		int lo = 0;
		int mid;
		int r;

		while(hi>=lo){
            //printf("%d %d", lo, hi);
			mid = (hi+lo)/2;
			int par = 1;
			int last = cs[0]+mid;
			while(1){
				int x = lower_bound(cs, cs+ns, last) - cs;
				if(x<ns){
					par++;
					last = cs[x] + mid;
				}
				else break;
			}
			//printf(" %d %d\n", mid, par);
			if(par<nc) hi = mid-1;
			if(par>=nc) {r = mid; lo = mid+1;}
		}
		printf("%d\n", r);
	}
	return 0;
}
