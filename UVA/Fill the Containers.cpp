#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000
#define ff                first
#define ss                second

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int x, n;
    while(scanf("%d %d", &x, &n)==2){
        int lo = 0, hi = 1000000000;
        vector <int> cap(x);
        for(int i = 0; i<x; i++){
            scanf("%d", &cap[i]);
            if(cap[i]>lo) lo = cap[i];
        }
        int mid, ans = INT_MAX;
        while(lo<=hi){
        	mid = (lo+hi)/2;
        	if(lo==hi) break;
        	int part = 0, cnt = 0;
        	for(int i = 0; i<x; i++){
        		if(cnt+cap[i]<=mid) cnt += cap[i];
        		else{
        			part++;
        			cnt = cap[i];
        		}
        		if(i==x-1) part++;
        	}
        	if(part<=n){
                hi = mid;
                ans = mid;
            }
        	else lo = mid+1;
        }
        cout<<ans<<endl;
    }
}
