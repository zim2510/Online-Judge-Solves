#include <bits/stdc++.h>

using namespace std;

int nodes[10001][2];
int last;

void  dfs(int node, int h, vector< vector <int> > &edges)
{
	if(nodes[node][0]) return;
	nodes[node][0] = h;
	nodes[node][1] = ++last;
	int x = 1;
	for(int i = 0; i<edges[node].size(); i++){
		if(node!=1) dfs(edges[node][i], nodes[node][1], edges);
		else dfs(edges[node][i], nodes[node][x%2], edges);
		x++;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
    while(scanf("%d", &n)==1){
    	vector<vector <int> > edges(10001);
    	for(int i = 0; i<n-1; i++){
    		int s, e;
    		scanf("%d %d", &s, &e);
    		edges[s].push_back(e);
    		edges[e].push_back(s);
    	}
    	if(n==2){
    		printf("1 2\n2 1\n");
    		continue;
    	}

    	last = 1;
    	dfs(1, 1, edges);
    	
    	for(int i = 1; i<=n; i++){
    		printf("%d %d\n", nodes[i][0], nodes[i][1]);
    		nodes[i][0] = nodes[i][1] = 0;
    	}
    }
    return 0;
}
