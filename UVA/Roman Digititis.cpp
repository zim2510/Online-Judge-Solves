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

int i, v, x, l, c;

void rcnt(int n)
{
	while(n)
	{
		if(n>=100){c++; n-=100;}
		else if(n>=90){x++, c++; n-=90;}
		else if(n>=50){l++; n-=50;}
		else if(n>=40){x++,l++; n-=40;}
		else if(n>=10){x++; n-=10;}
		else if(n>=9){i++, x++; n-=9;}
		else if(n>=5){v++; n-=5;}
		else if(n>=4){i++, v++; n-=4;}
		else if(n>=1){i++; n-=1;}
	}
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int n;
	while(scanf("%d", &n) && n){
		i = v = x = l = c = 0;
		for(int i = 1; i<=n; i++){
			rcnt(i);
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
	}

	return 0;
}