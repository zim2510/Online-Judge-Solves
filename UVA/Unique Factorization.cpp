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
#define MAX  2000001

using namespace std;

int prime[MAX], nprime[148935];
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
}

vector <int> factorized;
int cnt[1000];
void factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0) factorized.pb(nprime[i]);
		while(n%nprime[i]==0){
			cnt[factorized.size()-1]++;
			n /= nprime[i];
		}
	}
	if(n!=1){
		factorized.pb(n);
		cnt[factorized.size()-1]++;
	}
}

vector <int> divs;
int n;
void fdivs(int pos, int sum)
{
	if(pos==factorized.size()){
		if(sum!=1 && sum!=n) divs.pb(sum);
		return;
	}
	fdivs(pos+1, sum);
	for(int i = 1; i<=cnt[pos]; i++){
		sum *= factorized[pos];
		fdivs(pos+1, sum);
	}
}

vector <int> out;

int btrack(int pos, int min, int rmn, int sz)
{
	int lmt = sqrt(rmn);
	for(int i = pos; divs[i]<=lmt && divs[i]>=min; i++){
		if(rmn%divs[i]==0){
			if(sz>=out.size()) out.pb(0);
			out[sz] = divs[i];
			btrack(i, divs[i], rmn/divs[i], sz+1);
		}
	}
	if(rmn!=n){
		for(int i = 0; i<sz; i++){
			printf("%d ", out[i]);
		}
		printf("%d\n", rmn);
	}
}

int dcnt;
int btrackcnt(int pos, int min, int rmn, int sz)
{
	int lmt = sqrt(rmn);
	for(int i = pos; divs[i]<=lmt && divs[i]>=min; i++){
		if(rmn%divs[i]==0){
			if(sz>=out.size()) out.pb(0);
			out[sz] = divs[i];
			btrackcnt(i, divs[i], rmn/divs[i], sz+1);
		}
	}
	if(rmn!=n){
		dcnt++;
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	while(scanf("%d", &n) && n){
		if(n==1 || !prime[n]){
			printf("0\n");
			continue;
		}
		MEM(cnt, 0);
		factorized.clear();
		divs.clear();
		factorize(n);
		fdivs(0, 1);
		sort(divs.begin(), divs.end());
		dcnt = 0;
		btrackcnt(0, 0, n, 0);
		printf("%d\n", dcnt);
		btrack(0, 0, n, 0);
	}


	return 0;
}
