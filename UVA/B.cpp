#include <bits/stdc++.h>

using namespace std;

long long in[100005], tree[300005];

long long doOperation(long long x)
{
	long long n = (((x*x)%95542721)*x)%95542721;
	return n;
}

void buildtree(long long node, long long start, long long end)
{
	if(start==end){
		tree[node] = in[start];
		return;
	}

	long long left = node*2;
	long long right = left + 1;

	buildtree(left, start, (start+end)/2);
	buildtree(right, (start+end)/2 + 1, end);

	tree[node] = tree[left] + tree[right];
}

long long query(long long node, long long start, long long end, long long rstart, long long rend)
{
	if(max(start, rstart)>min(end, rend)) return 0;
	if(start>=rstart && end<=rend) return tree[node]%95542721;
	return (query(node*2, start, (start+end)/2, rstart, rend) + query(node*2+1, (start+end)/2+1, end, rstart, rend))%95542721;
}

void update(long long node, long long start, long long end, long long index, long long diff)
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
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	long long n;
	scanf("%lld", &n);
	for(long long i = 1; i<=n; i++) scanf("%lld", &in[i]);
	buildtree(1, 1, n);
	long long q;
	scanf("%lld", &q);
	for(long long i = 0; i<q; i++){
		long long qtype, s, e;
		scanf("%lld %lld %lld", &qtype, &s, &e);
		if(qtype==1){
			printf("%lld\n", query(1, 1, n, s, e));
		}
		else{
			//cout<<s<<" "<<e<<endl;
			for(long long i = s; i<=e; i++){
				long long x = doOperation(in[i]);
				long long diff = x - in[i];
				in[i] = x; 
				update(1, 1, n, i, diff);
			}
		}
	}
}
