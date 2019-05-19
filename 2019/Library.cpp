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
	for(int i = 0; i<nprime.size() && nprime[i]*nprime[i]<=n; i++){
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

ULL ncr[1005][1005];

LL nCr(int n, int r)
{
	if(ncr[n][r]!=-1) return ncr[n][r];
	if(n==r || r==0) return 1;
	return ncr[n][r] = ((nCr(n-1, r) + nCr(n-1, r-1)))%MOD;
}

ULL npr[1005][1005];

ULL nPr(int n, int r)
{
	if(npr[n][r]!=-1) return npr[n][r];
	if(n==0 || r==0)  return 1;
	return npr[n][r] = ((n*(nPr(n-1, r-1))))%MOD;
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

int baseFlag = 1;
vector <ULL> base(1, 1);
ULL BASE = 99571;
struct stringHash{

    string line;
    vector <ULL> hashed1, hashed2;

    void makeHash()
    {
        int sz = line.size();
        hashed1.resize(sz+5), hashed2.resize(sz+5);

        while(baseFlag<(sz+5)){
    		base.pb(base[baseFlag-1]*BASE);
    		baseFlag++;
    	}

        for(int i = 1; i<=sz; i++){
            hashed1[i] = hashed1[i-1]*BASE + line[i-1];
        }
        for(int i = sz; i>0; i--){
            hashed2[i] = hashed2[i+1]*BASE + line[i-1];
        }
    }

    ULL getHash()
    {
        return hashed1[line.size()];
    }
    //Returns the hash of the substring (i, j), in one based indexing
    ULL getHash(int i, int j)
    {
        if(j<hashed1.size()) return hashed1[j] - hashed1[i-1]*base[j-i+1];
        else return 0;
    }
    //Returns the reverse hash of the substring (i, j), in one based indexing
    ULL getRHash(int i, int j)
    {
        if(j<hashed2.size()) return hashed2[i] - hashed2[j+1]*base[j-i+1];
        else return 0;
    }
};

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


//Sort + Inversion count
LL sort(int sp, int ep)
{
	//cout<<sp<<" "<<ep<<endl;
	if(sp==ep) return 0;
	int mid = (sp+ep)/2;
	LL ecnt = 0;
	ecnt += sort(sp, mid);
	ecnt += sort(mid+1, ep);

	int i = sp;
	int j = mid+1;

	vector <int> sorted;

	int cnt = 0;

	while(i<=mid || j<=ep){
		if(i>mid) sorted.pb(nums[j++]);
		else if(j>ep) sorted.pb(nums[i++]);
		else if(nums[i]<nums[j]){
			sorted.pb(nums[i++]);
		}
		else{
			sorted.pb(nums[j++]);
			cnt += (mid-i+1);
		}
	}
	for(int i = sp; i<=ep; i++){
		nums[i] = sorted[i-sp];
	}
	return cnt+ecnt;
}

class Fraction
{
	int _n, _d;
public:
	Fraction(int n = 0, int d = 1){
		_n = n;
		_d = d;
	}

	int getNumerator(){ return _n; }
	int getDenominator(){ return _d; }
	void printValue() { printf("%d/%d\n", _n, _d); }

	Fraction operator + (const Fraction &rhs) const {
		int d = (_d*rhs._d)/__gcd(_d, rhs._d);
		int n = (d/_d)*_n + (d/rhs._d)*rhs._n;
		int g = __gcd(n, d);
		return Fraction(n/g, d/g);
	};

	Fraction operator - (const Fraction &rhs) const {
		int d = (_d*rhs._d)/__gcd(_d, rhs._d);
		int n = (d/_d)*_n - (d/rhs._d)*rhs._n;
		int g = __gcd(n, d);
		return Fraction(n/g, d/g);
	};

	Fraction operator * (const Fraction &rhs) const {
		int n = _n*rhs._n;
		int d = _d*rhs._d;
		int g = __gcd(n, d);
		return Fraction(n/g, d/g);
	};

	Fraction operator / (const Fraction &rhs) const {
		int n = _n*rhs._d;
		int d = _d*rhs._n;
		int g = __gcd(n, d);
		return Fraction(n/g, d/g);
	};

};

class Matrix
{
public:
	pair<LL, LL> dimension;
	vector <vector <LL> > M;

	Matrix(LL x, LL y){
		dimension = {x, y};
		M.resize(x);
		for(LL i = 0; i<x; i++) M[i].resize(y);
	}

	Matrix(const Matrix &m1, const Matrix &m2){
		dimension = {m1.dimension.ff, m2.dimension.ss};
		M.resize(m1.dimension.ff);
		for(LL i = 0; i<m1.dimension.ff; i++) M[i].resize(m2.dimension.ss);
	}
	
	void printMatrix(){
		for(LL i = 0; i<dimension.ff; i++){
			printf("%lld", M[i][0]);
			for(LL j = 1; j<dimension.ss; j++){
				printf(" %lld", M[i][j]);
			} printf("\n");
		}
	}

	void easyInput(){
		for(LL i = 0; i<dimension.ff; i++){
			for(LL j = 0; j<dimension.ss; j++){
				scanf("%lld", &M[i][j]);
			}
		}
	}
};

Matrix addMatrix(const Matrix &m1, const Matrix &m2)
{
	if(m1.dimension!=m2.dimension) return Matrix(0, 0);
	Matrix RES(m1, m2);
	for(LL i = 0; i<m1.dimension.ff; i++){
		for(LL j = 0; j<m2.dimension.ss; j++){
			RES.M[i][j] = m1.M[i][j] + m2.M[i][j];
		}
	}
	return RES;
}

Matrix multiplyMatrix(const Matrix &m1, const Matrix &m2)
{
	if(m1.dimension.ss!=m2.dimension.ff) return Matrix(0, 0);
	Matrix RES(m1, m2);

	if(rand()%2){

		for(LL i = 0; i<m1.dimension.ff; i++){
			for(LL j = 0; j<m1.dimension.ss; j++){
				for(LL k = 0; k<m2.dimension.ss; k++){
					RES.M[i][k] += m1.M[i][j] * m2.M[j][k];
				}
			}
		}
	}

	else{
		for(LL i = 0; i<m1.dimension.ss; i++){
			for(LL j = 0; j<m1.dimension.ff; j++){
				for(LL k = 0; k<m2.dimension.ss; k++){
					RES.M[j][k] += m1.M[j][i] * m2.M[i][k];
				}
			}
		}
	}

	return RES;
}

Matrix multiplyMatrix(const Matrix &m1, const Matrix &m2, LL mod)
{
	if(m1.dimension.ss!=m2.dimension.ff) return Matrix(0, 0);
	Matrix RES(m1, m2);


	for(LL i = 0; i<m1.dimension.ff; i++){
		for(LL j = 0; j<m1.dimension.ss; j++){
			for(LL k = 0; k<m2.dimension.ss; k++){
				RES.M[i][k] += m1.M[i][j] * m2.M[j][k];
				RES.M[i][k] %= mod;
			}
		}
	}


	return RES;
}

Matrix Identity(LL n)
{
	Matrix RES(n, n);
	for(LL i = 0; i<n; i++){
		RES.M[i][i] = 1;
	}
	return RES;
}

Matrix bigModMatrix(Matrix m, LL p, LL mod)
{
	if(p==0) return Identity(m.dimension.ff);
	if(p%2) return multiplyMatrix(m, bigModMatrix(m, p-1, mod), mod);
	Matrix M = bigModMatrix(m, p/2, mod);
	return multiplyMatrix(M, M, mod);
}