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

map <char, int> values;

void mapper()
{
	for(int i = '0'; i<='9'; i++) values[i] = i - '0';
	for(int i = 'A'; i<='Z'; i++) values[i] = i - 'A' + 10;
}

int convert(string s, int base)
{
	int ret = 0;
	for(int i = 0; i<s.size(); i++){
		if(values[s[i]]>=base) return -1;
		ret = ret*base + values[s[i]];
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	mapper();
	string s1, s2;
	while(cin>>s1>>s2){
		int r1 = 0, r2 = 0;
		for(int i = 2; i<=36; i++){
			int x = convert(s1, i);
			for(int j = 2; j<=36; j++){
				int y = convert(s2, j);
				if(x==y && x!=-1 && y!=-1){
					r1 = i;
					r2 = j;
					break;
				}
			}
			if(r1 && r2) break;
		}
		if(r1 && r2) cout<<s1<<" (base "<<r1<<") = "<<s2<<" (base "<<r2<<")"<<endl;
		else cout<<s1<<" is not equal to "<<s2<<" in any base 2..36"<<endl;
	}

	return 0;
}