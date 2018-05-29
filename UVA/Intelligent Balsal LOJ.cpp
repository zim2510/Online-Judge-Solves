#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size()) 
#define all(c)            (c).begin(),(c).end() 
#define tr(i,c)           for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               500
#define ff                first
#define ss                second
#define sf             	  scanf
#define pf 	              printf

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int prime[MAX], nprime[5555];
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

vector <int> pwr(100);
void factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		int cnt = 0;
		while(n%nprime[i]==0){
			n /= nprime[i];
			cnt++;
		}
		pwr[nprime[i]] += cnt;
	}
	if(n!=1) pwr[n]++;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		for(int i = 0; i<100; i++) pwr[i] = 0;
		int n;
		scanf("%d", &n);
		for(int i = 2; i<=n; i++) factorize(i);
		printf("Case %d: %d =", i, n);
		int flag = 0;
		for(int i = 0; i<100; i++){
			if(pwr[i] && flag) printf(" *");
			if(pwr[i]) flag = printf(" %d (%d)", i, pwr[i]);
		}
		printf("\n");
	}
}