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
#define MAX  65000

using namespace std;

int prime[MAX], nprime[6495];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
    }
    int n = 0;
    nprime[n++] = 2;
    for(int i = 3; i<MAX; i+=2){
        if(!prime[i]) nprime[n++] = i;
    }
}

long long bigmod(int base, int power, int mod){
	if(power==0) return 1;
	if(power%2) return ((base%mod)*bigmod(base, power-1, mod))%mod;
	long long int x = bigmod(base, power/2, mod);
	return (x*x)%mod;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int n;
	while(scanf("%d", &n) && n){
		int pos = 1;
		if(!prime[n]){
			pos = 0; 
		}
		if(pos) for(int i = 2; i<n; i++){
			if(bigmod(i, n, n)!=i){
				pos = 0;
				break;
			}
		}
		//printf("%d %d %d\n", n, prime[n], pos);
		if(pos) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
	

	return 0;
}