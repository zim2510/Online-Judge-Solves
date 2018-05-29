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

int coin[50];
int mark[50];
int coins, tables;
vector <int> lcms, nearvals;

void findvals(int pos, int sp, int lcm, int g)
{
	if(pos==4){
		if(!marker[lcm]){
			lcms.pb(lcm);
			marker[lcm] = 1;
		}
		return;
	}
	for(int i = 0; i<coins; i++){
		if(!mark[i]){
			mark[i] = 1;
			if(!g) findvals(pos+1, i+1, coin[i], coin[i]);
			else findvals(pos+1, i+1, (lcm*coin[i])/__gcd(lcm, coin[i]), __gcd(lcm, coin[i]));
			mark[i] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	while(scanf("%d %d", &coins, &tables) && (coins||tables)){
		lcms.clear();
		marker.clear();
		for(int i = 0; i<coins; i++){
			scanf("%d", &coin[i]);
		}
		findvals(0, 0, 1, 0);
		for(int i = 0; i<tables; i++){
			int n;
			scanf("%d", &n);
			nearvals.clear();
			for(int i = 0; i<lcms.size(); i++){
				int x = lcms[i] * (int) (n/lcms[i]);
				int y = x + lcms[i];
				nearvals.pb(x);
				nearvals.pb(y);
			}
			sort(nearvals.begin(), nearvals.end());
			int p1 = upper_bound(nearvals.begin(), nearvals.end(), n) - nearvals.begin();
			int p2 = lower_bound(nearvals.begin(), nearvals.end(), n) - nearvals.begin();
			printf("%d %d\n", nearvals[p1-1], nearvals[p2]);
		}
	}
	

	return 0;
}

