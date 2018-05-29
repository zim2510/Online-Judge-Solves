#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(long long i = a; i<=b; i++)
#define FOR(i, a, b)      for(long long i = a; i<b; i++)
#define ROF(i, a, b)      for(long long i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))
#define valid(x, s, e) 	  (x>=s && x<=e)
#define sz(a) 			  long long((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               10004
#define ff 				  first
#define ss				  second

using namespace std;


typedef vector<long long> vi;
typedef vector<vi> vvi;
typedef pair<long long,long long> ii;
typedef long long LL;
typedef unsigned long long ULL;

bool prime[MAX];
long long nprime[MAX/2];
long long nprimes = 0;

void siv()
{
    nprime[nprimes++]=2;
	for(long long i = 3; i<MAX; i+=2){
		if(!prime[i]){
                nprime[nprimes++]=i;
                for(long long x = i*i; x<MAX; x+=2*i) prime[x] = 1;
		}
	}
}

vector <pair<long long, long long> > factorized;
vector <pair<long long, long long> > range;

void factorize(long long n)
{
	for(long long i = 0; i<nprimes && nprime[i]*nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			long long cnt = 0;
			while(n%nprime[i]==0){
				n /= nprime[i];
				cnt++;
			}
			factorized.pb({nprime[i], cnt});
		}
	}
	if(n!=1){
		factorized.pb({n, 1});
	}
}
long long mod = 100000007;

long long abeer(long long n, long long m, long long b){
//    factorized.clear();
//    range.clear();
//    factorize(n);
    for(long long i = 0; i<factorized.size(); i++){
        factorized[i].ss *= m;
        long long rnge = factorized[i].ss/b;
        long long rngb = factorized[i].ss/(b+1) + 1;
        range.pb({rngb, rnge});
    }
    long long result = 0;
    for(long long i=0; i<factorized.size(); i++){
        long long st=range[i].ff;
        long long en=range[i].ss;
        long long tmp=en-st+1;
        for(long long j=0; j<factorized.size(); j++){
            if(i==j) continue;
            long long lim=range[j].ff;
            tmp*=(lim);
            if(tmp>=mod) tmp%=mod;
        }
        result+=(tmp%mod);
        if(result>=mod) result%=mod;
    }
    long long rem=factorized.size()>1?1:0;
    if(factorized.size()>1) for(long long i=0; i<factorized.size(); i++){
        long long st=range[i].ff;
        long long en=range[i].ss;
        rem*=(en-st+1);
        if(rem>=mod) rem%=mod;
    }
    result=(result+rem)%mod;
    return result;
}

int main(long long argc, char const *argv[])
{
//	Read();
	//Write();
	siv();
	long long n, m, b, tc = 0;
	while(scanf("%lld %lld %lld", &n, &m, &b) && (n+m+b)){
		factorized.clear();
		range.clear();
		factorize(n);
        printf("Case %lld: %lld\n", ++tc, abeer(n, m, b));
	}
}
