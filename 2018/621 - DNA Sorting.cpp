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

int mergesort(string &x, int lo, int hi)
{
    if(lo==hi) return 0;
    int mid = (lo+hi)/2;

    LL inversion = 0;
    inversion += mergesort(x, lo, mid);
    inversion += mergesort(x, mid+1, hi);

    vector <char> tmp;
    int i = lo, j = mid+1;
    while(i<=mid || j<=hi){
        if(i>mid) tmp.pb(x[j++]);
        else if(j>hi) tmp.pb(x[i++]);
        else if(x[i]<=x[j]) tmp.pb(x[i++]);
        else{
            inversion += mid - i + 1;
            tmp.pb(x[j++]);
        }
    }
    for(int i = 0; i<tmp.size(); i++){
        x[lo+i] = tmp[i];
    }
    return inversion;
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	sf("%d", &tc);
	TC(i, 1, tc){
		int n, m;
		sf("%d %d", &n, &m);
		vector <pair<ii, string> > nampaina;
		for(int i = 0; i<m; i++){
			string tmp, t;
			cin>>tmp;
			t = tmp;
			nampaina.pb({{mergesort(t, 0, n-1), i}, tmp});
		}
		sort(nampaina.begin(), nampaina.end());
		for(int i = 0; i<nampaina.size(); i++) cout<<nampaina[i].ss<<endl;
		if(i!=tc) cout<<endl;
	}
}