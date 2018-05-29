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

int b2d(string x)
{
	int n = 0;
	for(int i = 0; i<x.size(); i++){
		n = n*2 + x[i]-'0';
	}
	return n;
}



int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		string s1, s2;
		cin>>s1>>s2;
		int n1 = b2d(s1);
		int n2 = b2d(s2);
		if(__gcd(n1, n2)!=1) printf("Pair %d: All you need is love!\n", i);
		else printf("Pair #%d: Love is not all you need!\n", i);
	}
	

	return 0;
}