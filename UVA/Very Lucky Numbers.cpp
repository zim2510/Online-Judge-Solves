#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))
#define valid(x, s, e) 	  (x>=s && x<=e)
#define sz(a) 			  int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000000
#define ff 				  first
#define ss				  second

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

vector <LL> nlucky;
vector <LL> nvlucky;
map<LL, bool> mark;

void lucky()
{
	nlucky.pb(4);
	nlucky.pb(7);
	for(int i = 0; i<nlucky.size(); i++){
		LL n = nlucky[i]*10 + 4;
		if(n<MAX) nlucky.pb(n);
		if(n+3<MAX) nlucky.pb(n+3);
	}
}

void vlucky(int index, LL num)
{
	if(num>MAX || num<=0) return;
	if(num>1 && mark[num]==0){
        nvlucky.pb(num);
        mark[num] = 1;
	}
	for(int i = index; i<nlucky.size(); i++){
        LL tmp = num * nlucky[i];
        if(tmp>MAX || tmp<=0) break;
        vlucky(i, tmp);
	}
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	lucky();
	vlucky(0, 1);
	sort(nvlucky.begin(), nvlucky.end());
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
        LL sp, ep;
        scanf("%lld %lld", &sp, &ep);
        int cnt = upper_bound(nvlucky.begin(), nvlucky.end(), ep) - lower_bound(nvlucky.begin(), nvlucky.end(), sp);
        printf("Case %d: %d\n", i, cnt);
	}
}
