#include <bits/stdc++.h>

using namespace std;

int in[100000], tree[200000];

void buildtree(int node, int start, int end)
{
	if(start==end){
		tree[node] = in[start];
		return;
	}

	int left = node*2;
	int right = left + 1;

	buildtree(left, start, (start+end)/2);
	buildtree(right, (start+end)/2 + 1, end);

	tree[node] = tree[left] + tree[right];
}

int query(int node, int start, int end, int rstart, int rend)
{
	if(max(start, rstart)>min(end, rend)) return 0;
	if(start>=rstart && end<=rend) return tree[node];
	return query(node*2, start, (start+end)/2, rstart, rend) + query(node*2+1, (start+end)/2+1, end, rstart, rend);
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

	int n;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++) scanf("%d", &in[i]);
	buildtree(1, 1, n);
	update(1, 1, n, 10, 10);
	while(1){
		int s, e;
		scanf("%d %d", &s, &e);
		if(s && e){
			printf("%d %d: %d\n", s, e, query(1, 1, n, s, e));
		}
		else break;
	}
}
