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

int opt[4][(1<<20)+10];
int x, stick[25];

bool checkbit(int n, int bit){ return n&(1<<bit); }
int flip(int n, int bit){
	if(checkbit(n, bit)) return n = n & !(1<<bit);
	else return n = n | (1<<bit);
}

int side[4];
int start = 1;

int dp(int index, int state, int sum)
{
	if(index==4) return 1;
	if(opt[index][state]==start) return opt[index][state];

	opt[index][state] = start;

	for(int i = 0; i<x; i++){
		int x = start;
		if(!checkbit(state, i)){
			 //cout<<index<<" "<<i<<" "<<stick[i]<<" "<<side[index]<<endl;
			 if(side[index]+stick[i]<sum){
			 	side[index] += stick[i];
			 	x = dp(index, flip(state, i), sum);
			 	side[index] -= stick[i];
			 }
			 else if(side[index]+stick[i]==sum){
			 	//printf("HERE\n");
			 	side[index] += stick[i];
			 	x = dp(index+1, flip(state, i), sum);
			 	side[index] -= stick[i];
			 }
		}
		if(x==1){
			opt[index][state] = x;
			break;
		}
	}
	return opt[index][state];
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	sf("%d", &tc);
	TC(i, 1, tc){
		int s = 0;
		sf("%d", &x);
		for(int i = 0; i<x; i++){
			sf("%d", &stick[i]);
			s += stick[i];
		}
		start++;
		if(s%4) printf("no\n");
		else printf("%s\n", (dp(0, 0, s/4))==1?"yes":"no");
	}
}
