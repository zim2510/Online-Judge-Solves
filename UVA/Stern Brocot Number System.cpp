#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int main(int argc, char const *argv[])
{
	// Read();
	// Write();
	int iu, id;
	int tc = 0;
	while(scanf("%d %d", &iu, &id) == 2){
		tc++;
		if(iu==1 && id==1) break;
		int lu = 0, ld = 1, ru = 1, rd = 0, mu = 1, md = 1;
		double r = (double) iu/ (double) id;

		while(iu!=mu || id!=md){
			//printf("%d %d\n", mu, md);
            double mid = (double) mu / (double) md;
			if(mid>r){
				printf("L");
				ru = mu;
				rd = md;
				mu = mu + lu;
				md = md + ld;
			}
			else{
				printf("R");
				lu = mu;
				ld = md;
				mu = mu + ru;
				md = md + rd;
			}
		} printf("\n");
	}
	return 0;
}
