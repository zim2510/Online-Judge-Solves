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
#define MAX               10000
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

int prime[MAX/2], nprime[1230];
int nprimes = 0;
void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i>>1]) for(int x = i*i; x<MAX; x+=2*i) prime[x>>1] = 1;
	}
	nprime[nprimes++] = 2;
	for(int i = 1; i<(MAX>>1); i++){
		if(!prime[i]) nprime[nprimes++] = (i<<1)+1;
	}
}

int pwr[1230];
void factorize(int n)
{
	for(int i = 0; i<nprimes && nprime[i]<=n; i++){
		if(n%nprime[i]==0){
			int cnt = 0;
			while(n%nprime[i]==0){
				n /= nprime[i];
				cnt++;
			}
			pwr[i] = max(pwr[i], cnt);
		}
	}
}

int bigmod(int n, int p)
{
	if(p==0) return 1;
	if(p%2) return n*bigmod(n, p-1);
	int x = bigmod(n, p/2);
	return x*x;
}

string sum(string num1, string num2)
{
	string result = "";
	int mx = max(num1.size(), num2.size());
	int carry = 0;
	
	for(int i = 0; i<mx; i++){
		if(i<num1.size() && i<num2.size()){
			int x = (num1[i]+num2[i]-'0'-'0'+carry);
			carry = (x>=10);
			if(x>=10) x -= 10;
			result += x + '0';
			
		}
		else if(i<num1.size()){
			int x = (num1[i]-'0'+carry);
			carry = (x>=10);
			if(x>=10) x-= 10;
			result += x + '0';
		}
		else{
			int x = (num2[i]-'0'+carry);
			carry = (x>=10);
			if(x>=10) x-= 10;
			result += x + '0';
		}
	}

	if(carry) result += '0' + carry;
	return result;
}

string multiply(string num1, string num2)
{
	string init = "";
	string final = "";
	for(int i = 0; i<num1.size(); i++){
		string result = "";
		int carry = 0;
		for(int j = 0; j<num2.size(); j++){
			int res = carry + ((num1[i]-'0')*(num2[j]-'0'));
			result += '0' + (res%10);
			carry = res/10;
		}
		if(carry) result += carry + '0';
		result = init + result;
		final = sum(result, final);
		init += '0';
	}
	return final;
}

string num2string(int num)
{
	string x = "";
	while(num){
		x += '0' + num%10;
		num /= 10;
	}
	return x;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		MEM(pwr, 0);
		int n;
		scanf("%d", &n);
		for(int i = 0; i<n; i++){
			int x;
			scanf("%d", &x);
			factorize(x);
		}
		string ans = "1";
		for(int i = 0; i<nprimes; i++){
			if(pwr[i]){
				ans = multiply(num2string(bigmod(nprime[i], pwr[i])), ans);
			}
		}
		reverse(ans.begin(), ans.end());
		printf("Case %d: %s\n", i, ans.c_str());
		
	}
}