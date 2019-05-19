#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long LL;

LL bigmod(LL n, LL p, LL mod)
{
	if(p==0) return 1;
	if(p%2) return (n*bigmod(n, p-1, mod))%mod;
	LL x = bigmod(n, p/2, mod);
	return (x*x)%mod;
}

int MAX = 100000;

vector<int> prime(MAX/2), nprime;
int nprimes = 0;
void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i>>1]) for(int x = i*i; x<MAX; x+=2*i) prime[x>>1] = 1;
	}
	nprime.pb(2);
	for(int i = 1; i<(MAX>>1); i++){
		if(!prime[i]) nprime.pb((i<<1)+1);
	}
}

int main()
{
	freopen("out.txt", "w", stdout);
	siv();
	for(int x = 2; x<=100000; x++){
		int flag = 1;

		for(int i = 0; i<10; i++){
			int tmp = rand();
			if(bigmod(tmp, x, x)!=tmp%x){
				flag = 0;
				break;
			}
		}

		if(flag && prime[x/2]) printf("%d\n", x);
	}
	
}