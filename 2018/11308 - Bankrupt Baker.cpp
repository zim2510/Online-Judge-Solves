#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);

	while(tc--){
		map<string, int> cost;
		string name;
        getchar();
		getline(cin, name);
		//cout<<name<<endl;
		int n, m, d;
		cin>>n>>m>>d;
		//cout<<n<<" "<<m<<" "<<d<<endl;
		for(int i = 0; i<n; i++){
			string item;
			int price;
			cin>>item>>price;
			cost[item] = price;
		}
		vector <pair<int, string> > cakes;
		for(int i = 0; i<m; i++){
			string name;
			getchar();
			getline(cin, name);
			//cout<<"X "<<name<<endl;
			int n;
			cin>>n;
			int price = 0;
			for(int i = 0; i<n; i++){
				string item;
				int amount;
				cin>>item>>amount;
				//cout<<item<<amount<<endl;
				price += cost[item]*amount;
			}
			if(price<=d){
				cakes.push_back({price, name});
			}
		}
		sort(cakes.begin(), cakes.end());

		for(int i = 0; i<name.size(); i++) name[i] = toupper(name[i]);
		cout<<name<<endl;
		if(cakes.empty()) cout<<"Too expensive!"<<endl;
		for(int i = 0; i<cakes.size(); i++) cout<<cakes[i].second<<endl;
		cout<<endl;

	}
}
