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
#define sf             	  scanf
#define pf 	              printf

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int nums[200005];

LL sort(int sp, int ep)
{
	//cout<<sp<<" "<<ep<<endl;
	if(sp==ep) return 0;
	int mid = (sp+ep)/2;
	LL ecnt = 0;
	ecnt += sort(sp, mid);
	ecnt += sort(mid+1, ep);

	int i = sp;
	int j = mid+1;

	vector <int> sorted;

	int cnt = 0;

	while(i<=mid || j<=ep){
		if(i>mid) sorted.pb(nums[j++]);
		else if(j>ep) sorted.pb(nums[i++]);
		else if(nums[i]<nums[j]){
			sorted.pb(nums[i++]);
		}
		else{
			sorted.pb(nums[j++]);
			cnt += (mid-i+1);
		}
	}
	for(int i = sp; i<=ep; i++){
		nums[i] = sorted[i-sp];
	}
	return cnt+ecnt;
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int tc;
    sf("%d", &tc);

    TC(i, 1, tc){
    	int n;
    	sf("%d", &n);
    	FOR(i, 0, n) sf("%d", &nums[i]);
    	cout<<sort(0, n-1)<<endl;
    }
}
