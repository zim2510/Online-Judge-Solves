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
	int tp;
	int n, year[100001];
	while(scanf("%d", &tp)==1){
		scanf("%d", &n);
		year[0] = -100;
		for(int i = 1; i<=n; i++) scanf("%d", &year[i]);
		int mx = 0;
		int ss, se;
		for(int i = 1; i<=n; i++){
			if(year[i]==year[i-1]) continue;
			int te = upper_bound(year, year+n, year[i]+tp-1) - year;
			int t = te - i;
			//printf("%d %d %d\n", year[i], ts, te);
			if(t>mx){
				mx = t;
				se = te;
				ss = i;	
			}
		}
		printf("%d %d %d\n", mx, year[ss], year[se-1]);
	}

	return 0;
}