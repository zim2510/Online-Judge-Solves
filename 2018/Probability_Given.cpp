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

vector <int> taken;
vector <double> ans;
vector <double> p;
vector <int> mark;
int n, k;
double total;

void bt(int ci, int sp)
{
	if(ci==k){
		double pro = 1;
		for(int i = 0; i<n; i++){
			if(mark[i]) pro *= p[i];
			else pro *= (1-p[i]);
		}
		for(int i = 0; i<k; i++){
			//cout<<taken[i]<<" ";
			ans[taken[i]] += pro;
		}
		total += pro;
		return;
	}
	
	for(int i = sp; i<n; i++){
		if(!mark[i]){
			mark[i] = 1;
			taken[ci] = i;
			bt(ci+1, i+1);
			mark[i] = 0;
		}
	}
}


int main(int argc, char const *argv[])
{
	//Read();
    //Write();

    int tc = 0;
    while(sf("%d %d", &n, &k) && (n || k)){
    	p.resize(n);
    	ans.clear();
    	mark.resize(n);
    	ans.resize(n);
    	taken.resize(k);
    	total = 0;

    	for(int i = 0; i<n; i++){
    		sf("%lf", &p[i]);
    	}
    	bt(0, 0);
    	printf("Case %d:\n", ++tc);
    	for(int i = 0; i<n; i++){
    		printf("%0.6lf\n", ans[i]/total);
    	}
    }
}
