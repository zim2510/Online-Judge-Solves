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
	double x = sqrt(2);
	double n, p, s, v;
	while(scanf("%lf %lf %lf %lf", &n, &p, &s, &v)==4){
		double bestc, bestt = 1000000000000000000;
		double lo = 0, hi = 100, c1, c2;
		for(int i = 0; i<200; i++){
			c1 = lo+(hi-lo)/3;
			c2 = hi-(hi-lo)/3;
			double r1 = (n*pow(log2(n), c1*x))/((p*1000000000)) + s*(1.0 + 1.0/c1)/v;
			double r2 = (n*pow(log2(n), c2*x))/((p*1000000000)) + s*(1.0 + 1.0/c2)/v;
			if(r2<r1){
				if(r2<bestt && r2>=0){
					bestc = c2;
					bestt = r2;
				}
				lo = c1;
			}
			else{
				if(r1<bestt && r1>=0){
					bestc = c1;
					bestt = r1;
				}
				hi = c2;
			}
		}
		printf("%0.9f %0.9f\n", bestt, bestc);
	}
	return 0;
}