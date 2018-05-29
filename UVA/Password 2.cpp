#include <bits/stdc++.h>

using namespace std;

string grid1[6], grid2[6];
vector <string> gen;
map<string, int> chk;

void generate(int ci, string x)
{
	if(ci==5){
		chk[x] = 1;
		return;
	}
	for(int i = 0; i<6; i++){
		generate(ci+1, x+grid1[i][ci]);
	}
}

void generate2(int ci, string x)
{
	if(ci==5){
		if(chk.find(x)!=chk.end() && chk[x]==1) {gen.push_back(x); chk[x]++;} 
		return;
	}
	for(int i = 0; i<6; i++){
		generate2(ci+1, x+grid2[i][ci]);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	for(int i = 0; i<tc; i++){
		gen.clear();
		chk.clear();
		int o;
		cin>>o;
		for(int i = 0; i<6; i++) cin>>grid1[i];
		for(int i = 0; i<6; i++) cin>>grid2[i];
		generate(0, "");
		generate2(0, "");
		if(gen.size()<o) cout<<"NO"<<endl;
		else{
			sort(gen.begin(), gen.end());
			cout<<gen[o-1]<<endl;;
		}
	}
}