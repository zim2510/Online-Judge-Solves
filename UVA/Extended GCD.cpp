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

int egcd(int a, int b, int *x1, int *y1)
{
	if(b==0){
		*x1 = 1;
		*y1 = 0;
		return a;
	}
	int x, y;
	egcd(b, a%b, &x, &y);
	*x1 = y;
	*y1 = x - (a/b)*y;
	printf("%d %d\n", *x1, *y1);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int a, b;
	while(scanf("%d %d", &a, &b)==2){
		int x, y;
		egcd(a, b, &x, &y);
		printf("%d %d\n", x, y);
	}
	return 0;
}