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
#define MAX               1000000000
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


//Binary to Decimal Converter
int b2d(string x)
{
	int n = 0;
	for(int i = 0; i<x.size(); i++){
		n = n*2 + x[i]-'0';
	}
	return n;
}

//Total Prime Sieve
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
//Bitwise Sieve
int prime[10000000/64];
int nprime[664589];
int nprimes = 0;
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int sset(int N,int pos){	return N=N | (1<<pos);}
void siv()
{
	for(int i = 3; i*i<=MAX; i+=2){
		if(!check(prime[i>>6], (i&((1<<7)-1))>>1)) for(int x = i*i; x<MAX; x+=2*i) prime[x>>6] = sset(prime[x>>6], (x&((1<<7)-1))>>1);
	}
	nprime[nprimes++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!check(prime[i>>6], (i&((1<<7)-1))>>1)) nprime[nprimes++] = i;
	}
}

//Prime Factorization
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

//Extended Euclid GCD
int x, y, d;
void extendedEuclid(int a, int b)
{
	if(b==0) {x = 1; y = 0; d = a; return;}
	extendedEuclid(b, a%b);
	int x1 = y;
	int y1 = x - (a/b)*y;
	x = x1;
	y = y1;
	return a;
}


//Extended Euclid
LL egcd(LL a, LL b, LL *x1, LL *y1)
{
    if(b==0){
    	*x1 = 1;
    	*y1 = 0;
    	return a;
    }
    LL x, y;
    LL g = egcd(b, a%b, &x, &y);
    *x1 = y;
    *y1 = x - (a/b)*y;
    return g;
}


//Euler Phi Sieve
int ephi[10000000];

void phisiv()
{
	ephi[0] = 1; for(int i = 1; i<MAX; i++) ephi[i] = i;
	for(int i = 2; i<MAX; i++){
		if(ephi[i]==i){
			for(int x = i; x<MAX; x += i){
				ephi[x] -= (ephi[x]/i);
			}
		}
	}
}


string num2string(int num, int base)
{
	string x = "";
	while(num){
		x += '0' + (num%base);
		num /= base;
	}
	return x;
}

struct stringHash{
    string x;
    ULL base[1000010], hashed1[1000010], hashed2[1000010];
    void makeHash()
    {
        int sz = x.size();
        base[0] = 1;
        hashed1[0] = hashed2[0] = 0;
        for(int i = 1; i<=sz; i++){
            hashed1[i] = hashed1[i-1]*99571 + x[i-1];
            base[i] = base[i-1] * 99571;
        }
        for(int i = sz; i>0; i--){
            hashed2[i] = hashed2[i+1]*99571 + x[i-1];
        }
    }
    ULL getHash()
    {
        return hashed1[x.size()];
    }
    //Returns the hash of the substring (i, j), in one based indexing
    ULL getHash(int i, int j)
    {
        //cout<<i<<" "<<j<<endl;
        return hashed1[j] - hashed1[i-1]*base[j-i+1];
    }

    ULL getRHash(int i, int j)
    {
        return hashed2[i] - hashed2[j+1]*base[j-i+1];
    }
};

class disset{
	public:
	std::vector <int> par;
	disset(int n)
	{
		par.resize(n);
		for(int i = 0; i<n; i++) par[i] = i;
	}

	int Find(int node)
	{
	    if(par[node]==node) return node;
	    par[node] = Find(par[node]);
	    return par[node];
	};

	void Union(int node1, int node2)
	{
	    int x = Find(node1);
	    int y = Find(node2);
	    par[x] = y;
	}
};