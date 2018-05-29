#include <bits/stdc++.h>

using namespace std;

int in[150000], tree[300000];

void doOperation(int &node, int value1, int value2){
	node = min(value1, value2);
}

void buildtree(int node, int start, int end)
{
	if(start==end){
		doOperation(tree[node], in[start], in[start]+1);
		return;
	}

	int left = node*2;
	int right = left + 1;

	buildtree(left, start, (start+end)/2);
	buildtree(right, (start+end)/2 + 1, end);

	doOperation(tree[node], tree[left], tree[right]);
}

int query(int node, int start, int end, int rstart, int rend)
{
	if(max(start, rstart)>min(end, rend)) return INT_MAX;
	if(start>=rstart && end<=rend) return tree[node];
	int result;
	return doOperation(result, query(node*2, start, (start+end)/2, rstart, rend), query(node*2+1, (start+end)/2+1, end, rstart, rend));
}

void update(int node, int start, int end, int index, int diff)
{
	if(start>index || end<index) return;
	else{
		tree[node] += diff;
		if(start!=end) update(node*2, start, (start+end)/2, index, diff);
		if(start!=end) update(node*2+1, (start+end)/2+1, end, index, diff);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i = 1; i<=n; i++) scanf("%d", &in[i]);
		buildtree(1, 1, n);
		printf("Case %d:\n", i);
		for(int i = 0; i<q; i++){
			int s, e;
			scanf("%d %d", &s, &e);
			printf("%d\n", query(1, 1, n, s, e));
		}
	}
}
