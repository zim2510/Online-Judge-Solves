#include <bits/stdc++.h>

using namespace std;

string grid1[6], grid2[6];

void btrack(int col, string x, vector <string> &gens)
{
	if(col==5){
		gens.push_back(x);
		return;
	}
	for(int i = 0; i<6; i++){
		for(int j = 0; j<6; j++){
			if(grid1[i][col]==grid2[j][col]){
				btrack(col+1, x+grid1[i][col], gens);
			}
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	for(int i = 0; i<tc; i++){
		vector <string> gens;
		int order;
		cin>>order;
		for(int i = 0; i<6; i++) cin>>grid1[i];
		for(int i = 0; i<6; i++) cin>>grid2[i];
		btrack(0, "", gens);
		if(gens.size()<order) cout<<"NO"<<endl;
		else{
			sort(gens.begin(), gens.end());
			cout<<gens[order-1]<<endl;;
		}
	}
}