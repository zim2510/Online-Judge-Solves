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

string nums[505];

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

void makenum()
{
	nums[0] = "0";
	for(int i = 1; i<501; i++){
		nums[i] = sum(nums[i-1], "1");
		//cout<<nums[i]<<endl;
	}
}

string factorials[501];
int result[501];

void calfact()
{
	factorials[0] = "1";
	for(int i = 1; i<501; i++){
		factorials[i] = mul(factorials[i-1], nums[i]);
		//cout<<factorials[i-1]<<" "<<nums[i]<<endl;
		//cout<<factorials[i]<<endl;
	}
	for(int i = 0; i<501; i++){
		int sum = 0;
		for(int j = 0; j<factorials[i].size(); j++){
			sum += factorials[i][j] - '0';
			//cout<<factorials[i][j]<<endl;
		}
		result[i] = sum;
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	makenum();
	calfact();
	int n;
	while(scanf("%d", &n)==1){
		printf("%d\n", result[n]);
	}

	return 0;
}