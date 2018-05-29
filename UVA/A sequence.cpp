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
#define sf                scanf
#define pf                printf

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;
int nums[30];
int mark[30];
int check(int ep, int sum)
{
	
	if(sum==nums[ep]) return 0;
	for(int i = 0; i<ep && sum+nums[i]<=nums[ep]; i++){
		if(!mark[i]){
			mark[i] = 1;
			//cout<<"marking "<<i<<endl;
			int x = check(ep, sum+nums[i]);
			//cout<<"x "<<x<<endl;
			mark[i] = 0;
			if(x==0) return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int n, tc = 0;
    while(scanf("%d", &n)==1){
        int flag = 1;
        FOR(i, 0, n){
            scanf("%d", &nums[i]);
            if(!i && nums[i]<1) flag = 0;
            if(i && nums[i]<=nums[i-1]) flag = 0;
            //cout<<flag<<endl;
            if(flag && !check(i, 0)) flag = 0;
            //cout<<flag<<endl;
            
        }
        printf("Case #%d:", ++tc);
        FOR(i, 0, n) printf(" %d", nums[i]);
        printf("\nThis is %san A-sequence.\n", flag?"":"not ");
    }
}
