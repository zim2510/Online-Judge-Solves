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

bool mark[40001];

void Precalc()
{
	for(int i = 2; i<=40000; i++){
		int valid = SQR(i);
		for(int x = 10; x<valid; x*=10){
			int sum = valid/x + valid%x;
			if(sum == i && valid%x){
				mark[i] = 1;
				break;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	Precalc();
	int tc;
	scanf("%d", &tc);

	TC(i, 1, tc){
		int rs, re, cnt = 0;
		scanf("%d %d", &rs, &re);
		printf("case #%d\n", i);
		TC(i, rs, re){
			if(mark[i]) {printf("%d\n", i); cnt++; }
		}
		if(!cnt) pf("no kaprekar numbers\n");
		printf("\n");
	}
}