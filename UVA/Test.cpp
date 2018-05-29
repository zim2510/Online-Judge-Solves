#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define MAX	 				10000007
#define MOD 				1000000009
#define base 				1000000007
#define INF                 1llu<<62
#define inf 				1<<30
#define PI                  acos(-1.0)
#define ll	 				long long
#define ul 					unsigned long
#define ull 				unsigned long long
#define vi 					vector<int>
#define pb 					push_back
#define ii 					pair<int, int>
#define MP 					make_pair
#define ff 					first
#define ss 					second
#define SQR(x) 				((x)*(x))
#define FOR(i, x, y) 		for(int i=(x); i<(y); i++)
#define ROF(i, x, y) 		for(int i=(x-1); i>=(y); i--)
#define sf 					scanf
#define pf 					printf
#define all(c) 				c.begin(), c.end()
#define sz(c) 				int(c.size())
#define CLR(x, y) 			memset(x, y, sizeof(x))
#define fastIO 				ios_base::sync_with_stdio(false)
#define tr(container, it) 	for(auto it = container.begin(); it != container.end(); it++)
#define sc1(x) 				scanf("%d", &x)
#define sc2(x, y) 			scanf("%d %d", &x, &y)
#define sc3(x, y, z)		scanf("%d %d %d", &x, &y, &z)
// template <typename T> using orderset = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// *X.find_by_order(1) // X.order_of_key(1)
template <class T> inline T bigMod(T p,T e,T M){
        ll ret = 1;
        for(; e > 0; e >>= 1){
                if(e & 1) ret = (ret * p) % M;
                p = (p * p) % M;
        } return (T)ret;
}
template <class T> inline T modInverse(T a,T M){return bigmod(a,M-2,M);}


int par1[MAX];
int par2[MAX];

int main(){
    #ifdef VAMP
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    while(sc1(n)==1){
    	CLR(par1, 0);
    	CLR(par2, 0);
    	n++;
    	int left=0, right=0, f=0, last=1;
    	for(int i=1; i<=n; i++){
    		int x;
    		sc1(x);
    		if(last>1 && x>1){
    			f=1;
    			for(int i=right+1, j=0; j<x; j++, i++){
    				par1[i]=left;
    			}
    			par2[right+1]=left;
    			for(int i=right+2, j=1; j<x; i++, j++){
    				par2[i]=right;
    			}
    		}
    		else if(last==1){
    			for(int i=right+1, j=0; j<x; i++, j++) par1[i]=par2[i]=left;
    		}
    		else{
    			par1[right+1]=par2[right+1]=left+(last+1)/2;
    		}
    		left=right+1;
    		right=left+x-1;
    		last=x;
    	}
    	if(!f) printf("perfect\n");
    	else{
    		printf("ambiguous\n");
    		for(int i=1; i<=right; i++) printf("%d ", par1[i]); printf("\n");
    		for(int i=1; i<=right; i++) printf("%d ", par2[i]); printf("\n");
    	}
    }
    return 0;
}