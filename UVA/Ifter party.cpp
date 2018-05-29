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
#define MAX               50000
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

vector <int> factorized, pwr;
void factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			factorized.pb(nprime[i]);
			int cnt = 0;
			while(n%nprime[i]==0){
				n /= nprime[i];
				cnt++;
			}
			pwr.pb(cnt);
		}
	}
	if(n!=1){
		factorized.pb(n);
		pwr.pb(1);
	}
}

set <int> divs;
void finddivs(int n, int total)
{
	if(n==factorized.size()){
		divs.insert(total);
		return;
	}
	finddivs(n+1, total);
	for(int i = 1; i<=pwr[n]; i++){
		total *= factorized[n];
		finddivs(n+1, total);
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		factorized.clear();
		pwr.clear();
		divs.clear();
		int p, l;
		scanf("%d %d", &p, &l);
		int n = p-l;
		factorize(n);
		finddivs(0, 1);
		bool flag = 0;
		printf("Case %d:", i);
		for(set<int>::iterator i = divs.begin(); i!=divs.end(); i++){
			if(*i>l){
				flag = 1;
				printf(" %d", *i);
			}
		}
		if(!flag) printf(" impossible");
		printf("\n");
	}
}