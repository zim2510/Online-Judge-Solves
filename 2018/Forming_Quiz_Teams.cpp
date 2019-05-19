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

vector <ii> co;
int n;

double dis(int i, int j)
{
	double x = sqrt(double(SQR(co[i].ff-co[j].ff) + SQR(co[i].ss-co[j].ss)));
	//cout<<"Distance "<<i<<" "<<j<<" :"<<x<<endl;
	return x;
}

double mn = 10E10;

bool check(int n, int pos){	return bool(n&(1<<pos)); }
int flip(int n, int pos){
	if(n&(1<<pos)) n = n & !(1<<pos);
	else n = n | (1<<pos);
	return n;
}

double opt[17][(1<<17)+10];

double backtrack(int ci, int mark)
{
	//cout<<ci<<" "<<opt[ci][mark]<<endl;
	if(ci==n) return 0;
	if(opt[ci][mark]>0) return opt[ci][mark];
	
	opt[ci][mark] = INT_MAX;

	for(int i = 0; i<2*n; i++){
		if(check(mark, i) == 0){
			for(int j = i+1; j<2*n; j++){
				if(check(mark, j)==0){
					int x = flip(mark, i);
					x = flip(x, j);
					opt[ci][mark] = min(dis(i, j) + backtrack(ci+1, x), opt[ci][mark]);
				}
			}
		}
	}

	return opt[ci][mark];
}

int main(int argc, char const *argv[])
{
	Read();
	Write();

	int tc = 0;
	while(true){
		sf("%d", &n);
		if(!n) break;
		co.resize(n*2);

		for(int i = 0; i<2*n; i++){
			string hudai;
			int x, y;
			cin>>hudai>>co[i].ff>>co[i].ss;
		}
		for(int i = 0; i<17; i++){
			for(int j = 0; j<(1<<17)+10; j++){
				opt[i][j] = -1;
			}
		}
		printf("Case %d: %0.2lf\n", ++tc, backtrack(0, 0));
	}
}
