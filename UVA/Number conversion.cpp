#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector <vector <int> > divs(1005);

void siv()
{
	for(int i = 4; i<1005; i+=2){
		divs[i].pb(2);
	}
	for(int i = 3; i<1005; i+=2){
		if(divs[i].size()==0){
			for(int j = 2*i; j<1005; j+=i){
				divs[j].pb(i);
			}
		}
	}
}


int mn;
int opt[1005][1005];

int dfs(int num, int tr)
{
	if(num==tr) return 0;
	if(num>tr) return INT_MAX/10;
	if(opt[num][tr]!=-1) return opt[num][tr];

	opt[num][tr] = INT_MAX;

	for(int i = 0; i<divs[num].size(); i++){
		opt[num][tr] = min(opt[num][tr], 1+dfs(num+divs[num][i], tr));
	}
	return opt[num][tr];
}


int main()
{
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	siv();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int x, t;
		scanf("%d %d", &x, &t);
		memset(opt, -1, sizeof(opt));
		mn = dfs(x, t);
		printf("Case %d: %d\n", i, mn>=INT_MAX/10?-1:mn);
	}
}