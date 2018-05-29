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

/*int mod[10001];

int bigmod(int power, int m)
{
	if(mod[power]==-1) return mod[power];
	else if(power%2) mod[power] = (2*bigmod(power/2, m))%m;
	else mod[power] = (bigmod(power/2, m) * bigmod(power/2, m))%m;
	return mod[power];
}*/

int main()
{
	//Read();
	//Write();
	string input;
	int res = 0;
	while(cin>>input){
		for(int i = 0; i<input.size(); i++){
			if(input[i]=='#'){
				if(res==0) printf("YES\n");
				else printf("NO\n");
				res = 0;
			}
			else res = (res*2+input[i]-'0')%131071;
		}
	}
}
