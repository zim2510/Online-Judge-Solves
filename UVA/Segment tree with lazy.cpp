#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct nodes
{
    LL sum = 0;
    LL pro = 0;
};
 
nodes tree[300000];
 
void buildtree(LL node, LL s, LL e)
{
    if(s==e){
        tree[node].sum = 0;
        tree[node].pro = 0;
        return;
    }
    buildtree(node*2, s, (s+e)/2);
    buildtree(node*2+1, (s+e)/2+1, e);
    tree[node].sum = 0;
    tree[node].pro = 0;
}
 
LL query(LL node, LL s, LL e, LL rs, LL re, LL carry)
{
    if(min(re, e)<max(rs, s)) return 0;
    if(s>=rs && e<=re){
        return tree[node].sum + (carry)*(e-s+1);
    }
    return query(node*2, s, (s+e)/2, rs, re, carry+tree[node].pro) + query(node*2+1, (s+e)/2+1, e, rs, re, carry+tree[node].pro);
}
 
void update(LL node, LL s, LL e, LL rs, LL re, LL delta)
{
    if(min(re, e)<max(rs, s)) return;
    if(s>=rs && e<=re){
        tree[node].pro += delta;
        tree[node].sum += (e-s+1)*delta;
        return;
    }
    update(node*2, s, (s+e)/2, rs, re, delta);
    update(node*2+1, (s+e)/2+1, e, rs, re, delta);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum + (e-s+1)*tree[node].pro;
}
 
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    LL tc;
    scanf("%lld", &tc);
    for(LL i = 1; i<=tc; i++){
        LL n, q;
        scanf("%lld %lld", &n, &q);
        buildtree(1, 1, n);
        printf("Case %lld:\n", i);
        while(q--){
            LL qtype;
            scanf("%lld", &qtype);
            if(!qtype){
                LL e, s, delta;
                scanf("%lld %lld %lld", &s, &e, &delta);
                update(1, 1, n, s+1, e+1, delta);
            }
            else{
                LL s, e;
                scanf("%lld %lld", &s, &e);
                printf("%lld\n", query(1, 1, n, s+1, e+1, 0));
            }
        }
    }
}