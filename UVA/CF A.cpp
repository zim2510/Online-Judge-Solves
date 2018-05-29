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

int star[105][105];
int starf[105][105];
int start[15][105][105];
int tree[100000];

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int n;
	for(int i = 0; i<n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x>y) swap(x, y);
		if(tree[x*2]==0) tree[x*2] = y;
		else tree[x*2+1] = y;
	}
	return 0;
}