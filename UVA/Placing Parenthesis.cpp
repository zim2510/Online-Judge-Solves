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

LL nums[17], n = 0;
LL opr[17], o = 0;
LL mx[17][17];
LL mn[17][17];

LL eval(LL x, LL y, char s){
	if(s=='+') return x + y;
	if(s=='-') return x - y;
	if(s=='*') return x * y;
}

LL fmin(int l, int r)
{
	LL m = MAX;
	for(int k = l; k<r; k++){
		LL a = eval(mx[l][k], mx[k+1][r], opr[k]);
		LL b = eval(mn[l][k], mn[k+1][r], opr[k]);
		LL c = eval(mx[l][k], mn[k+1][r], opr[k]);
		LL d = eval(mn[l][k], mx[k+1][r], opr[k]);
		m = min3(a, b, m);
		m = min3(c, d, m);
	}

	return m;
}

LL fmax(int l, int r)
{
	LL m = MAX * -1;
	for(int k = l; k<r; k++){
		LL a = eval(mx[l][k], mx[k+1][r], opr[k]);
		LL b = eval(mn[l][k], mn[k+1][r], opr[k]);
		LL c = eval(mx[l][k], mn[k+1][r], opr[k]);
		LL d = eval(mn[l][k], mx[k+1][r], opr[k]);
		m = max3(a, b, m);
		m = max3(c, d, m);
	}

	return m;
}


int main()
{
	Read();
	Write();

	char in[100];
	scanf("%s", in);
	int len = strlen(in);

	for(int i = 0; i<len; i++){
		if(i%2) opr[o++] = in[i];
		else nums[n++] = in[i] - '0';
	}

	for(int i = 0; i<n; i++){
		mx[i][i] = nums[i];
		mn[i][i] = nums[i];
	}

	for(int diff = 1; diff<n; diff++){
		for(int i = 0; i<n-diff; i++){
			int j = i + diff;
			mn[i][j] = fmin(i, j);
			mx[i][j] = fmax(i, j);
		}
	}
	printf("%lld\n", mx[0][n-1]);
	return 0;
}

