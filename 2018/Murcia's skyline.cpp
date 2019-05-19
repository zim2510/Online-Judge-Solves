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


int n;
int h[10000], l[10000], in[10000], d[10000]; 

int LIS(int pos)
{
	if(in[pos]!=-1) return in[pos];
	in[pos] = l[pos];
	FOR(i, pos+1, n){
		if(h[i]>h[pos]) in[pos] = max(in[pos], l[pos] + LIS(i));
	}
	return in[pos];
}

int LDS(int pos)
{
	if(d[pos]!=-1) return d[pos];
	d[pos] = l[pos];
	FOR(i, pos+1, n){
		if(h[i]<h[pos]) d[pos] = max(d[pos], l[pos] + LDS(i));
	}
	return d[pos];
}

int main(int argc, char const *argv[])
{
	//Read();
    //Write();
    
    int tc;
    scanf("%d", &tc);

    TC(i, 1, tc){
    	MEM(in, -1);
    	MEM(d, -1);
    	sf("%d", &n);
    	FOR(i, 0, n) sf("%d", &h[i]);
    	FOR(i, 0, n) sf("%d", &l[i]);

    	int lds = 0, lis = 0;

    	FOR(i, 0, n){
    		lds = max(lds, LDS(i));
    		lis = max(lis, LIS(i));
    	}

    	printf("Case %d. ", i);

    	if(lis>=lds){
    		printf("Increasing (%d). Decreasing (%d).\n", lis, lds);
    	}
    	else{
    		printf("Decreasing (%d). Increasing (%d).\n", lds, lis);
    	}
    }
}
