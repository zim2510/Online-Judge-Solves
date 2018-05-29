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
#define MAX  2703700

using namespace std;

int prime[MAX], nprime[196900], np = 0, mx;
int npf[MAX];

void siv()
{
	for(int i = 2; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[np++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[np++] = i;
	}
}

void calc()
{
	for(int i = 0; i<np-1; i++){
        long long int n = nprime[i];
		while(n<=MAX){
			for(int i = n; i<MAX; i+=n) npf[i]++;
			n *= nprime[i];
		}
	}
	for(int i = 1; i<MAX; i++){
      npf[i] += npf[i-1];
      if(npf[i]>10000001){
        mx = i;
        break;
      }
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	calc();
	int n, t = 1;
	while(scanf("%d", &n) && n>=0){
        int x = lower_bound(npf, npf+mx, n) - npf;
        printf("Case %d: ", t++);
        if(npf[x]==n){
            printf("%d!\n", x);
        }
        else printf("Not possible.\n");
	}

	return 0;
}
