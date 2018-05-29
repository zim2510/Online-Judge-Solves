#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

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

string outs[366];

int main(int argc, char const *argv[])
{
	Read();
	Write();
	outs[1] = "1";
	for(int i = 2; i<30; i++){
		string x;
		int n = i;
		while(n){
			x = x  + ("0"+n%10);
			n /= 10;
		}
		cout<<"P: "<<x<<endl;
		reverse(x.begin(), x.end());
		outs[i] = mul(outs[i-1], x);
	}

	return 0;
}