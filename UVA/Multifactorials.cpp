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
#define MAX  501

using namespace std;

int prime[MAX], nprime[95];
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

int faccnt[501];

void factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		while(n%nprime[i]==0){
			faccnt[nprime[i]]++;
			n /= nprime[i];
		}
	}
	if(n!=1) faccnt[n]++;
}

void calc(int sp, int diff, int ep)
{
	if(sp<ep) return;
	factorize(sp);
	calc(sp-diff, diff, ep); 
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		string s;
		cin>>s;
		int n = 0, k = 0;
		for(int i = 0; i<s.size(); i++){
			if(s[i]=='!'){
				k = s.size() - i;
				break;
			}
			n = n*10 + s[i]-'0';
		}
		MEM(faccnt, 0);
		if(n%k) calc(n, k, n%k);
		else calc(n, k, k);
		LL res = 1;
		for(int i = 0; i<=500; i++){
			res *= (faccnt[i]+1);
			if(res>1e10){
				res = -1;
				break;
			}
		}
		printf("Case %d: ", i);
		if(res>0) printf("%lld\n", res);
		else printf("Infinity\n");
	}
	return 0;
}