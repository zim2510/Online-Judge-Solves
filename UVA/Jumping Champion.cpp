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
#define MAX  1000000

using namespace std;

int prime[MAX], nprime[78498];
int nprimes;
void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[nprimes++] = i;
	}
}


int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i<tc; i++){
		int lb, ub;
		scanf("%d %d", &lb, &ub);
		int diff[1000];
		MEM(diff, 0);
		int sp = lower_bound(nprime, nprime+nprimes, lb) - nprime;
		int ep = upper_bound(nprime, nprime+nprimes, ub) - nprime;
		int pos = 1, mx = 0;
		if(ep-sp<2) pos = 0;
		for(int i = sp; i<ep-1; i++){
			int d = nprime[i+1]-nprime[i];
			diff[d]++;
			//printf("%d %d %d\n", nprime[i+1], nprime[i], diff[d]);
			if(diff[d]>mx) mx = diff[d];
		}
		int ans = 0, cnt = 0;
		for(int i = 0; i<1000; i++){
			if(diff[i]==mx) ans = i, cnt++;
			if(cnt==2){
				pos = 0;
				break;
			}
		}
		if(pos) printf("The jumping champion is %d\n", ans);
		else printf("No jumping champion\n");
	}

	return 0;
}