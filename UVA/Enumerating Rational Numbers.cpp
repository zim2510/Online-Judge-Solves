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
#define MAX  200001

using namespace std;

int ephi[200001];
LL sumphi[200001];
int nprime[MAX], nprimes = 0;

void phisiv()
{
	ephi[0] = 1; for(int i = 1; i<MAX; i++) ephi[i] = i;
	for(int i = 2; i<MAX; i++){
		if(ephi[i]==i){
			nprime[nprimes++] = i;
			for(int x = i; x<MAX; x += i){
				ephi[x] -= (ephi[x]/i);
			}
		}
	}
	sumphi[0] = 1;
	for(int i = 1; i<MAX; i++) sumphi[i] = sumphi[i-1] + ephi[i];
}

int katar[MAX];
int katakuti(int lmt, int n)
{
	
	int cnt = 0;
	for(int i = 1; i<lmt; i++){
		if(__gcd(i, lmt)==1) cnt++;
		if(cnt==n) return i;
	}
}

int solve(LL n)
{
	int x = 0, rest;
	x = lower_bound(sumphi, sumphi+MAX, n) - sumphi;
	rest = n - sumphi[x-1];
	int y = katakuti(x, rest);
	printf("%d/%d\n", y,x);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	phisiv();
	LL n;
	while(scanf("%lld", &n) && n){
        if(n==1) printf("0/1\n");
        else if(n==2) printf("1/1\n");
        else solve(n);
	}
	return 0;
}
