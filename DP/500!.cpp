#include<bits/stdc++.h>
using namespace std;
#define MAX 10000007
#define lli long long int
#define llu unsigned long long

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

string itoa(int n)
{
    string a;
    int i = 0;
    while(n)
    {
        a += '0' + (n%10);
        n = n/10;
    }
    reverse(a.begin(), a.end());
    return a;
}

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

string fac[1001];

string facto(int n)
{
    if(n==0 || n==1) return "1";
    if(fac[n].empty()==0) return fac[n];
    fac[n] = mul(facto(n-1), itoa(n));
    return fac[n];
}

int main()
{
    int n;
    while(scanf("%d", &n)==1){
        printf("%d!\n", n);
        printf("%s\n", facto(n).c_str());
    }
}
