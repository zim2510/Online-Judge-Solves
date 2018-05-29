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
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               1000000000
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

//BigInteger Addition
string sum(string a, string b){
	string c;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i=0;
	int s=0;
	int lim=max(a.size(), b.size());
	while(i<lim){
		if(i<a.size()) s+=a[i]-'0';
		if(i<b.size()) s+=b[i]-'0';
		c+=(s%10+'0');
		s/=10;
		i++;
	}
	while(s){
		c+=(s%10+'0');
		s/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}

//BigInteger Multiplication
string mul(string a, string b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int v[3000];
	memset(v, 0, sizeof(v));
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			v[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	int lim=a.length()+b.length()-1;
	string c;
	int carry=0;
	for(int i=0; i<lim; i++){
		v[i]+=carry;
		c+=(v[i]%10+'0');
		carry=v[i]/10;
	}
	while(carry){
		c+=(carry%10+'0');
		carry/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}


string sum(string num1, string num2, int base)
{
	string result = "";
	int mx = max(num1.size(), num2.size());
	int carry = 0;
	for(int i = 0; i<mx; i++){
		if(i<num1.size() && i<num2.size()){
			result += '0' + (num1[i]-'0'+num2[i]-'0'+carry)%base;
			carry = (num1[i]-'0'+num2[i]-'0'+carry)/base;
		}
		else if(i<num1.size()){
			result += (num1[i]-'0'+carry)%base + '0';
			carry = (num1[i]-'0'+carry)/base;
		}
		else{
			result += (num2[i]-'0'+carry)%base + '0';
			carry = (num2[i]-'0'+carry)/base;
		}
	}
	if(carry) result += '0' + carry;
	return result;
}

string multiply(string num1, string num2, int base)
{
	string init = "";
	string final = "";
	for(int i = 0; i<num1.size(); i++){
		string result = "";
		int carry = 0;
		for(int j = 0; j<num2.size(); j++){
			int res = carry + ((num1[i]-'0')*(num2[j]-'0'));
			result += '0' + (res%base);
			carry = res/base;
		}
		if(carry) result += carry + '0';
		result = init + result;
		final = sum(result, final, base);
		init += '0';
	}
	reverse(final.begin(), final.end());
	return final;
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