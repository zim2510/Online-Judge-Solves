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

string outs[367];
string num[367];
int cnt[10];

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	num[0] = "0";
	for(int i = 1; i<=366; i++){
		num[i] = sum(num[i-1], "1");
	}

	outs[1] = "1";

	for(int i = 2; i<=366; i++){
		outs[i] = mul(outs[i-1], num[i]);
	}
	int n;
	while(scanf("%d", &n) && n){
		MEM(cnt, 0);
		for(int i = 0; i<outs[n].size(); i++){
			cnt[outs[n][i]-'0']++;
		}
		printf("%d! --\n", n);
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n", cnt[5], cnt[6], cnt[7], cnt[8], cnt[9]);
	}
	return 0;
}

