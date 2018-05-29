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

int mark[100010];

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	
	int m, n;
	char ballon[100010];
	scanf("%d %d", &n, &m);
	scanf(" %s", ballon);

	int R=0, G=0, B=0;
	for(int i = 0; i<n; i++){
		if(ballon[i]=='R') R++;
		else if(ballon[i]=='G') G++;
		else if(ballon[i]=='B') B++;
	}

	for(int i = 0; i<m; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		for(int i = s-1; i<e; i++){
			if(!mark[i]){
				mark[i] = 1;
				if(ballon[i]=='R'){ballon[i] = 'B'; R--; B++;}
				else if(ballon[i]=='G') {ballon[i] = 'R'; G--; R++;}
				else if(ballon[i]=='B') {ballon[i] = 'G'; B--; G++; }
			}
		}
		printf("%d %d %d\n", R, G, B);
	}
}