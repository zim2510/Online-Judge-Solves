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

int prime[MAX], nprime[5500];

void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	int n = 0;
	nprime[n++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[n++] = i;
	}
	printf("%d\n", n);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	//siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		vector<int> vals;
		int n;
		int pos = 1;
		scanf("%d", &n);
		if(n==1){
			printf("%d\n", 1);
			continue;
		}
		while(n!=1){
			int sn = n;
			for(int i = 9; i>1; i--){
				if(n%i==0){
					n/=i;
					vals.pb(i);
					break;
				}
			}
			if(sn==n){
				pos = 0;
				break;
			}
		}
		if(pos==0) printf("-1");
		else for(int i = vals.size()-1; i>=0; i--) printf("%d", vals[i]);
		printf("\n");
	}

	return 0;
}