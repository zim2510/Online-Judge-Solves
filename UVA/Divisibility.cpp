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

int opt[10000][100], num[10000];
int nt, d;

int dp(int ci, int mod)
{
	if(mod<0) mod += d;
	if(ci==nt){
		if(mod==0) return 1;
		else return 0;
	}
	if(opt[ci][mod]!=-1) return opt[ci][mod];
	opt[ci][mod] = dp(ci+1, (mod+num[ci])%d) || dp(ci+1, (mod-num[ci])%d);
	return opt[ci][mod];
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		MEM(opt, -1);
		scanf("%d %d", &nt, &d);
		for(int i = 0; i<nt; i++) scanf("%d", &num[i]);
		if(dp(0,0)) printf("Divisible\n");
		else printf("Not divisible\n");

	}

	return 0;
}