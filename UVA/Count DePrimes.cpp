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
#define MAX  5000001

using namespace std;

int prime[MAX];

void siv()
{
    for(int i = 2; i<MAX; i++){
        if(!prime[i]) for(int x = 2*i; x<MAX; x+=i) prime[x] += i;
    }
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int sp, ep;
	while(scanf("%d", &sp) && sp){
		scanf("%d", &ep);
		int cnt = 0;
		for(int i = sp; i<=ep; i++){
			if(!prime[prime[i]])    cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}