#include <bits/stdc++.h>

#define Read() freopen("in.txt", "r", stdin)
#define Write() freopen("out.txt", "w", stdout)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define REP(i, a, b) for(int i = a; a<=b; i++)
#define FOR(i, a, b) for(int i = a; a<b; i++)
#define MEM(a, x) memset(a, x, sizeof(a))

#define pb push_back
#define LL long long
#define ULL unsigned long long
#define MAX 1000001

int prime[MAX], primes[78500], ncnt[1000000];

using namespace std;

void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i){
			prime[x] = 1;
		}
	}
	int x = 0;
	primes[x++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) primes[x++] = i;
	}
}

int main()
{
    //Read();
    //Write();
	siv();
	int n;
	while(scanf("%d", &n) && n){
		for(int i = 0; i<78498 && primes[i]<=n; i++){
			int x = n;
			int cnt = 0;
			while(x>=primes[i]){
				cnt++;
				x /= primes[i];
			}
			ncnt[i] = cnt;
		}
		int r = 1;
		ncnt[0] -= ncnt[2];
		ncnt[2] = 0;
		for(int i = 0; i<78498 && primes[i]<=n; i++){
			for(int j = 0; j<ncnt[i]; j++){
				r *= primes[i];
				r %= 10;
			}
		}
		printf("%d\n", (r)%10);
	}
}
