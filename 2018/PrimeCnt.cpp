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
#define MAX               10000005
#define ff                first
#define ss                second
#define sf             	  scanf
#define pf 	              printf
 
const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;
 
vector<int> prime(MAX/2), nprime;
int nprimes = 0;
void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i>>1]) for(int x = i*i; x<MAX; x+=2*i) prime[x>>1] = 1;
	}
	nprime.pb(2);
	for(int i = 1; i<(MAX>>1); i++){
		if(!prime[i]) nprime.pb((i<<1)+1);
	}
}
 
ULL primecnt[10005][105];
 
ULL countphi(LL n, LL k)
{
	if(k==1) return (n+1)/2;
	if(k==0) return n;
 
	LL result = countphi(n, k-1) - countphi(n/nprime[k-1], k-1);
 
	if(n<=10000 && k<=100)	primecnt[n][k] = result;
 
	return result;
}
 
int main(int argc, char const *argv[])
{
	
	MEM(primecnt, -1);
	siv();
 	for(int i = 0; i<15; i++) cout<<nprime[i]<<endl;
	int tc = 0;
	//sf("%d", &tc);
 
	TC(i, 1, tc){
		ULL n;
		sf("%llu", &n);
		
		ULL answer = 0;		
 
		for(int i = 1; nprime[i-1]*nprime[i-1]<=n; i++){
			answer += nprime[i-1] * (countphi(n, i-1) - countphi(n, i));
		}
 
 
		//I have to optimize this part. But how??
		for(int i = 0; nprime[i]<=n; i++){
			if(nprime[i]*nprime[i]<=n) continue;
			answer += nprime[i];
		}
 
		printf("%llu\n", answer);
	}
}  