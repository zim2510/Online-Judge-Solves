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
	int n, tc = 0;
	while(scanf("%d", &n)==1){
		set <int> sums;
		int cnt = 0, flag = 1;
		vector <int> nums(n);
		for(int i = 0; i<n; i++) sf("%d", &nums[i]);
		for(int i = 0; i<n; i++){
			if(!i && nums[i]<1) flag = 0;
			if(i && nums[i]<=nums[i-1]) flag = 0;
			for(int j = i; j<n; j++){
				sums.insert(nums[i]+nums[j]);
				cnt++;
			}
		}
		if(sums.size()!=cnt) flag = 0;
		if(flag) printf("Case #%d: It is a B2-Sequence.\n", ++tc);
		else printf("Case #%d: It is not a B2-Sequence.\n", ++tc);
		printf("\n");
	}
}