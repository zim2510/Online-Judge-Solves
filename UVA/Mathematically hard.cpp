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
#define MAX               5000005
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

int ephi[MAX];

void phisiv()
{
	ephi[0] = 1; for(int i = 1; i<MAX; i++) ephi[i] = i;
	for(int i = 2; i<MAX; i++){
		if(ephi[i]==i){
			for(int x = i; x<MAX; x += i){
				ephi[x] -= (ephi[x]/i);
			}
		}
	}
}
ULL result[MAX];

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	phisiv();
	result[0] = 1;
	for(int i = 1; i<MAX; i++){
		result[i] = result[i-1] + (ULL) SQR((ULL)ephi[i]);
	}
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("Case %d: %llu\n", i, result[e]-result[s-1]);
	}
}