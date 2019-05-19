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

vector <LL> lookup;
void precalc()
{
	lookup.pb(1);
	while(lookup[lookup.size()-1]<=1000000000000000) lookup.pb(lookup[lookup.size()-1]*2);
}

LL calc(LL start, LL end, LL want)
{
	
	LL ans = 0;
	want = want / 2 + 1;
	for(int i = 0; i<lookup.size() && lookup[i]+want-1<=end; i++){
		if(lookup[i]>=want && lookup[i]+want-1>=start && lookup[i]+want-1<=end) ans++;
	}
	return ans;
}


int main()
{
	Read();
	Write();

	precalc();


	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		LL pos, mn, total, ans = 0;
		scanf("%lld %lld %lld", &pos, &mn, &total);
		ans = ((pos>mn)?(pos-mn):0) + ((pos%2)?calc(mn, total, pos):0);

		LL n = total - mn + 1;
		LL g = __gcd(ans, n);
		n /= g;
		ans /= g;
		cout<<"Case "<<i<<": ";
		if(ans==0) cout<<"0/1"<<endl;
		else cout<<ans<<"/"<<n<<endl;
	}
}
