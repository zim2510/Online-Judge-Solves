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

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	map<char, int> values;

	for(int i = 'a', val = 1; i<='z'; i++, val++){
		values[char(i)] = val;
	}
	for(int i = 'A', val = 27; i<='Z'; i++, val++){
		values[char(i)] = val;
	}

	char in[21];
	while(scanf(" %s", in)==1){
		int len = strlen(in);
		int sum = 0;
		for(int i = 0; i<len; i++){
			sum+=values[in[i]];
		}
		int p = 1;
		for(int i = 2; i<sum; i++){
			if(sum%i==0){
				p = 0;
				break;
			}
		}
		//printf("%d %d\n", sum, values['b']);
		if(p) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}
	return 0;
}