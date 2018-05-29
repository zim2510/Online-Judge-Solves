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
	int n;
	while(scanf("%d", &n) && n){
		int sol1 = 0, sol2 = 0;
		for(int i = 1; i<75; i++){
			for(int j = i+1; j<75; j++){
				if(j*j*j-i*i*i==n){
					sol1 = j;
					sol2 = i;
					break;
				}
				if(j*j*j-i*i*i>n) break;
			}
			if(sol1||sol2) break;
		}
		if(sol1==sol2) printf("No solution\n");
		else printf("%d %d\n", sol1, sol2);
	}
	

	return 0;
}