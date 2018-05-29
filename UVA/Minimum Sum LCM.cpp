#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  50001

using namespace std;

int prime[MAX], nprime[5133], np;

void siv()
{
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[np++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[np++] = i;
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int n, tc = 1;
	while(scanf("%d", &n) && n){
		LL sum  =  0, div = 0;
		for(int i = 0; i<np && nprime[i]*nprime[i]<n; i++){
			int temp = 1;
			while(n%nprime[i]==0){
				temp *= nprime[i];
				n /= nprime[i];
			}
			if(temp!=1) {sum += temp; div++;}
		}
		if(sum==0) sum = (LL) n + 1;
		else if(n==1){
			if(div==1) sum += 1;
		}
		else sum += n;
		printf("Case %d: %lld\n", tc++, sum);
	}
}