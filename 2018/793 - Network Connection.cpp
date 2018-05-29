#include <bits/stdc++.h>

using namespace std;

struct disset{
    vector <int> par;
    disset(int n)
    {
        par.resize(n+1);
        for(int i = 1; i<=n; i++) par[i] = i;
    }

    int Find(int node)
    {
        if(par[node]==node) return node;
        par[node] = Find(par[node]);
        return par[node];
    }

    void Union(int node1, int node2)
    {
        int x = Find(node1);
        int y = Find(node2);
        par[x] = y;
    }
};

int main()
{
	//freopen("in.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	getchar();

	while(tc--){
		int n, s = 0, f = 0;
		scanf("%d", &n);
		getchar();
		disset x(n);

		while(true){
			string in;
			getline(cin, in);
			stringstream input(in);
			if(in.size()==0) break;
			char c;
			int node1, node2;
			input>>c>>node1>>node2;
			if(c=='c') x.Union(node1, node2);
			if(c=='q'){
				int z = x.Find(node1);
				int y = x.Find(node2);
				s += z==y;
				f += z!=y;
			}
		}
		cout<<s<<","<<f<<endl;
		if(tc) cout<<endl;
	}
}