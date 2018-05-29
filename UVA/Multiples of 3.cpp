#include <bits/stdc++.h>

using namespace std;

int tree[300001][3];

void buildtree(int node, int start, int end)
{
	if(start==end){
		tree[node][0] = 1;
		return;
	}
	buildtree(node*2, start, (start+end)/2);
	buildtree(node*2+1, (start+end)/2+1, end);

	tree[node] = tree[node*2] + tree[node*2+1];
}

void update()



int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	buildtree();
	for()
}