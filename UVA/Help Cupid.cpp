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

int n, tzn[25], mark[25], mn;

void btrack(int pos, int tillnow)
{
	//printf("P: %d M: %d N: %d TN: %d\n", pos, mark[pos], tzn[pos], tillnow);
	if(pos==25){
		if(tillnow<mn) mn = tillnow;
		return;
	}
	if(mark[pos]==1 || !tzn[pos]){
		btrack(pos+1, tillnow);
		return;
	}
	for(int i = pos+1; i<25; i++){
		if(!mark[i] && tzn[i]){
			mark[i] = 1;
			btrack(pos+1, tillnow+min(i-pos, 24-(i-pos)));
			mark[i] = 0;
		}
	}

}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	while(scanf("%d", &n)==1){
		MEM(tzn, 0);
		mn = MAX;
		for(int i = 0; i<n; i++){
			int t;
			scanf("%d", &t);
			tzn[t+12]++;
			tzn[t+12] = tzn[t+12]%2;
		}

		btrack(0, 0);
		printf("%d\n", mn);
	}

	return 0;
}