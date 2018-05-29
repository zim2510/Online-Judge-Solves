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

int main(int argc, char const *argv[])
{
	Read();
	//Write();
	int tc;
	sf("%d", &tc);

	while(tc--){
		int lmt, n;
		scanf("%d %d", &lmt, &n);
		int total = lmt;
		for(int i = 1; lmt; i++){
			if(i%2) total -= lmt/n;
			else total += lmt/n;
			lmt /= n;
		}
		cout<<total<<endl;
	}
}