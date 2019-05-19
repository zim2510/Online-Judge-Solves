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
typedef pair<double, double> dd;
typedef long long LL;
typedef unsigned long long ULL;
 
vector <dd> ptsx;
vector <dd> ptsy;
 
bool cmp(dd x, dd y) { return x.ss<y.ss; }
 
double distance(dd x, dd y)
{
	return sqrt(SQR(x.ff-y.ff) + SQR(x.ss-y.ss));
}
 
double splitpair(vector <dd> px, vector <dd> py, double d)
{
	double midx = px[px.size()/2].ff;
	vector <dd> valid;
	FOR(i, 0, py.size()){
		if(valid(py[i].ff, midx-d, midx+d)) valid.pb(py[i]);
	}
	double best = d;
	FOR(i, 0, valid.size()){
		for(int j=i+1; j<i+8 && j<valid.size(); j++){
			best = min(best, distance(valid[i], valid[j]));
		}
	}
	return best;
}
 
double closestpair(vector <dd> px, vector <dd> py)
{
	if(px.size()<=3){
		double best = 100000000000000;
		FOR(i, 0, px.size()){
			FOR(j, i+1, px.size()){
				best = min(best, distance(px[i], px[j]));
			}
		}
		return best;
	}
 
	int mid = ((int)px.size())/2;
	double midx = px[mid].ff;
	vector <dd> fpx, spx, fpy, spy;
 
	FOR(i, 0, px.size()){
		if(i<=mid) fpx.pb(px[i]);
		else spx.pb(px[i]);
	}
	
	fpy = fpx;
	spy = spx;

	sort(fpy.begin(), fpy.end(), cmp);
	sort(spy.begin(), spy.end(), cmp);
	
	double best = min(closestpair(fpx, fpy), closestpair(spx, spy));
 
	best = min(best, splitpair(px, py, best));
 
	return best;
 
}
 
int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    int n;
    while(scanf("%d", &n)==1){
    	ptsx.resize(n);
    	FOR(i, 0, n) sf("%lf %lf", &ptsx[i].ff, &ptsx[i].ss);
    	ptsy = ptsx;
    	sort(ptsx.begin(), ptsx.end());
    	sort(ptsy.begin(), ptsy.end(), cmp);
    	double best = closestpair(ptsx, ptsy);
		printf("%0.6lf\n", best);
    }
}
 