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
#define MAX  10000

using namespace std;

int prime[MAX], nprime[1230];
int nprimes = 0;
void siv()
{
	prime[0] = prime[1] = 1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[nprimes++] = i;
	}
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


int nod[10001];
int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();

	for(int i = 1; i<=10000; i++){
		facto.clear();
		MEM(cnt, 0);
		nod[i] = factorize(i);
		//printf("%d: %d\n", i, nod[i]);
	}

	int tc;
	scanf("%d", &tc);
	while(tc--){
		int h, cnt = 0, l, start = 0;
		scanf("%d %d", &l, &h);
		l--;
		while(h>=++l){
			if(!prime[nod[l]]){
				if(start) printf(" ");
				printf("%d", l);
				start = 1;
				cnt++;
			}
		}
		if(!cnt) printf("-1");
		printf("\n");
	}

	return 0;
}