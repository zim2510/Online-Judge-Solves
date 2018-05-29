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

int prime[MAX], nprime[664579];
int nprimes = 0;
string cprime;
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

int mark[10];
int anagram(int sum, int pos)
{
	
	if(pos==cprime.size()){
		//printf("L: %d\n", sum);
		if(!prime[sum]) return 1;
		else return 0;
	}

	for(int i = 0; i<cprime.size(); i++){
		if(!mark[i]){
			mark[i] = 1;
			int r = anagram(sum*10+cprime[i]-'0', pos+1);
			mark[i] = 0;
			if(!r) return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int n;
	while(scanf("%d", &n) && n){
		int pos = upper_bound(nprime, nprime+nprimes, n) - nprime;
		//printf("P: %d\n", nprime[pos]);
		int fnd = 0;
		for(int i = pos; (int)log10(nprime[i])<=(int)log10(n); i++){
			cprime = "";
			int x = nprime[i];
			while(x){
				cprime += (x%10)+'0';
				x /= 10;
			}
			//cout<<"C: "<<cprime<<endl;
			if(anagram(0, 0)){
				fnd = 1;
				printf("%d\n", nprime[i]);
				break;
			}
		}
		if(!fnd) printf("0\n");
	}

	return 0;
}