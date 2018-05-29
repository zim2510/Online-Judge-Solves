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

int main()
{
	//Read();
	//Write();
	int n, tc = 0;
	while(scanf("%d", &n)==1){
		int result = 0;
		for(int i = 0; i<n; i++){
			int cnt = 0, ltr = 0;
			string x;
			cin>>x;
			vector <int> freq(256), idk, mark(50);
			for(int i = 0; i<x.size(); i++) freq[x[i]]++;
			for(int i = 0; i<freq.size(); i++){
				if(freq[i] && !mark[freq[i]]) idk.pb(freq[i]), cnt += freq[i], ltr++, mark[freq[i]] = 1;
			}
			if(cnt==x.size() && ltr>1) result++;
		}
		printf("Case %d: %d\n", ++tc, result);
	}
}