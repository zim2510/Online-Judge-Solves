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
vector <int> facto;
int factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			while(n%nprime[i]==0){
				cnt[facto.size()]++;
				n /= nprime[i];
			}
			facto.pb(nprime[i]);
		}
	}
	if(n!=1){
		cnt[facto.size()]++;
		facto.pb(n);
	}
	int ret = 1;
	for(int i = 0; i<facto.size(); i++){
		ret *= (cnt[i]+1);
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int n;
	while(scanf("%d", &n)==1){
        facto.clear();
        MEM(cnt, 0);
		int x, y;
		x = factorize(n);
		y = n;
		for(int i = 0; i<facto.size(); i++){
			y -= (y/facto[i]);
		}
		printf("%d\n", 1+n-(x+y));
	}

	return 0;
}
