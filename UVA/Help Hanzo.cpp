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
#define MAX               46340
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

vector<int> prime(MAX/2), nprime, mark(100005);
void siv()
{
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i>>1]) for(int x = i*i; x<MAX; x+=2*i) prime[x>>1] = 1;
	}
	nprime.pb(2);
	for(int i = 1; i<(MAX>>1); i++){
		if(!prime[i]) nprime.pb((i<<1)+1);
	}
}

int katakuti(int s, int e)
{
	for(int i = 0; i<nprime.size(); i++){
		int start = (s/nprime[i] + !((s/nprime[i])*nprime[i]==s))*nprime[i];
		if(start>e) break;
		if(!start) break;
		if(start==nprime[i]) start += nprime[i];
		for(int x = start; x<=e && x>=0; x+=nprime[i]){
			mark[x-s] = 1;
		}
	}
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	int tc;
	scanf("%d", &tc);
	TC(i, 1, tc){
		int s, e;
		int cnt = 0;
		scanf("%d %d", &s, &e);
		fill(mark.begin(), mark.end(), 0);
		katakuti(s, e);
		if(s==1) mark[0] = 1;
		for(int i = 0; i<=e-s; i++){
			//if(!mark[i]) cout<<s+i<<endl;
			if(!mark[i]) cnt++;
		}
		printf("Case %d: %d\n", i, cnt);
	}
}