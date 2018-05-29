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
#define eps  .000001

using namespace std;

struct mark
{
	double g, t;
};

mark marks[20000];
double mid;

bool cmp(mark a, mark b)
{
	return (a.g-(a.t*mid))>(b.g-(b.t*mid));
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int n, d;
		double best = 0;
		scanf("%d %d", &n, &d);
		for(int i = 0; i<n; i++) scanf("%lf %lf", &marks[i].g, &marks[i].t);
		double lo = 0, hi = 1;
		while(hi-lo>=eps){
			mid = (hi+lo)/2;
			sort(marks, marks+n, cmp);
			double up = 0, down = 0;
			for(int i = 0; i<n-d; i++){
				up += marks[i].g;
				down += marks[i].t;
			}
			double x = up/down;
			if(x<mid){
				hi = mid;
			}
			else{
				if(x>best) best = x;
				lo = mid;
			}
		}
		printf("Case %d: %0.9f\n", i, best*100);
	}

	return 0;
}