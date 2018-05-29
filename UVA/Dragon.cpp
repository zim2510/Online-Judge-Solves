#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))
#define sz(a) 			  int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               31623

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int prime[MAX], nprime[3405];
int nprimes = 0;
void siv()
{
	prime[0]=prime[1]=1;
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) nprime[nprimes++] = i;
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int n, div = 0, x;
	scanf("%d", &n);


	for(int i = 0; i<nprimes; i++){
		if(n%nprime[i]==0){
			div++;
			x = nprime[i];
		}
	}
	if((n>1 && div==0) || (n<31623 && !prime[n])){
		printf("yes\n");
		return 0;
	}
	int m = 1;
	for(int i = 1; m<=n; i++){
		m *= x;
		if(m==n){
			printf("yes\n");
			return 0;
		}
	}
	printf("no\n");
	return 0;

}
