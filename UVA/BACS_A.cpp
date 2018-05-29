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
	for(int i = 1; i<=tc; i++){
		int ascending = 1, descending = 1, same = 1;
		int mval[1000];
		int n;
		scanf("%d", &n);
		for(int i = 0; i<n; i++) scanf("%d", &mval[i]);
		for(int i = 1; i<n; i++){
			if(mval[i]-mval[i-1]<0){
				ascending = 0;
				break;
			}
		}
		for(int i = 1; i<n; i++){
			if(mval[i]-mval[i-1]>0){
				descending = 0;
				break;
			}
		}
		for(int i = 1; i<n; i++){
			if(mval[i]-mval[i-1]!=0){
				same = 0;
				break;
			}
		}
		if(same) printf("neutral\n");
		else if(ascending) printf("allGoodDays\n");
		else if(descending) printf("allBadDays\n");
		if(same || ascending || descending) return 0;
		int last = 0, latest = 0, mx = 0;
		for(int i = 1; i<n; i++){
			if(mval[i]>mval[i+1] && mval[i]>mval[i-1]){
				last = latest;
				latest = i;
				if(!last && latest-last>mx) mx = latest-last-1;
			}
		}
		if(!mx) printf("%s\n", "none");
		else printf("%d\n", mx);

	}

	return 0;
}
