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

int prime[MAX], nprime[664589];
int nprimes = 0;
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
	//printf("%d\n", nprimes);
}

int cnt[100];

int factorize(int n)
{
	for(int i = 0; nprime[i]*nprime[i]<=n; i++)
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n, mn = MAX, ans;
		scanf("%d", &n);

		for(int i = 0; nprime[i]<=n; i++){
			int x = n/nprime[i];
			if(nprime[i]*x<mn){
				mn = nprime[i]*x;
				ans = nprime[i];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
