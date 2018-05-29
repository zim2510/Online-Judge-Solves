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
	// Read();
	// Write();

	int pos[100000];
	int n, p;
	scanf("%d %d", &n, &p);
	for(int i = 1; i<=n; i++){
		int t;
		scanf("%d", &t);
		pos[t] = i;
	}
	int cheat = 0;
	for(int i = 0; i<p; i++){
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		int fp = min(pos[c1], pos[c2]);
		int lp = max(pos[c1], pos[c2]);

		int dis1 = lp - fp - 1;
		int dis2 = (n - 2) - dis1;
		if(dis1%2 || dis2%2) cheat++;
	}
	printf("%d\n", cheat);
}