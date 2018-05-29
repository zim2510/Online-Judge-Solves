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
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               10000000
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

vector <int> prime(10000000/64);
vector <int> nprime;
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int sset(int N,int pos){	return N=N | (1<<pos);}

void siv()
{
	for(int i = 3; i*i<=MAX; i+=2){
		if(!check(prime[i>>6], (i&((1<<7)-1))>>1)) for(int x = i*i; x<MAX; x+=2*i) prime[x>>6] = sset(prime[x>>6], (x&((1<<7)-1))>>1);
	}
	nprime.pb(2);
	for(int i = 3; i<MAX; i+=2){
		if(!check(prime[i>>6], (i&((1<<7)-1))>>1)) nprime.pb(i);
	}
}

int ans;
void factorize(LL n)
{
	for(int i = 0; i<nprime.size() && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			int cnt = 0;
			while(n%nprime[i]==0){
				n /= nprime[i];
				cnt++;
			}
			ans *= ((cnt+1)*2-1); 
		}
	}
	if(n!=1){
		ans *= 3;
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		LL n;
		ans = 1;
		scanf("%lld", &n);
		factorize(n);
		printf("Case %d: %d\n", i, (ans+1)/2);
	}
}