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

int input[100000];
vector <int> lis;
vector <int> ilis;
int prv[100000];
int path[1000000];

int main()
{
	Read();
	Write();
	MEM(prv, -1);
	int n = 0, mx = -MAX, last = 0;

	while(scanf("%d", &input[n++])==1);
	for(int i = 0; i<n; i++){
		int pos = lower_bound(lis.begin(), lis.end(), input[i]) - lis.begin();
		
		if(pos==(int)lis.size()){
			lis.pb(input[i]);
			ilis.pb(i);
			if(pos!=0) prv[i] = ilis[pos-1];
			int x = lis.size();
			if((int)lis.size()>mx){
				mx = lis.size();
				last = i;
			}
		}
		else{
			lis[pos] = input[i];
			ilis[pos] = i;
			if(pos!=0) prv[i] = ilis[pos-1];
		}
	}
	int i = 0;
	path[i++] = input[last];
	while(prv[last]!=-1){
		last = prv[last];
		path[i++] =  input[last];
	}
	printf("%d\n-\n", mx);
	for(int i = mx-1; i>=0; i--){
		printf("%d\n", path[i]);
	}
}