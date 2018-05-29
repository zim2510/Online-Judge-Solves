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
#define MAX  50000

using namespace std;


int prime[MAX];
int nprime[5133];

void siv()
{
	int n = 0;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}

	nprime[n++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[n++] = i;
	}
}

long long int bigmod(int base, int power, int mod)
{
	if(power==0) return 1;
	if(power%2) return (base%mod * bigmod(base, power-1, mod))%mod;
	long long int x = bigmod(base, power/2, mod);
	return (x*x)%mod;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int p, a;

	while(scanf("%d %d", &p, &a)==2 && (p||a)){
		int lmt = sqrt(p);
		int flag = 1;
		for(int i = 0; nprime[i]<lmt; i++){
			if(p%nprime[i]==0){
				flag = 0;
				break;
			}
		}
		if(flag==0 && bigmod(a, p, p)==a) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}