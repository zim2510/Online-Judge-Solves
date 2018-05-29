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

void calc(LL a, LL b)
{
	a--;
	LL last = b/4 + (b%4)/2;
	LL first = a/4 + (a%4)/2;
	printf("%lld\n", last-first);
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	LL a, b;
	while(scanf("%lld", &a)==1){
		char ch;
		scanf("%c", &ch);
		if(ch==' '){
			scanf("%lld", &b);
			calc(a, b);
			continue;
		}
		if(a%2){
			if(a>0) printf("%lld %lld\n", (a/2)+1, a/2);
			else printf("%lld %lld\n", (-a/2), ((-a/2)+1));
		}
		else if(a%4==0){
			if(a>0) printf("%lld %lld\n", (a/4+1), (a/4)-1);
			else printf("%lld %lld\n", (-a/4-1), (-a/4+1));
		}
		else printf("Bachelor Number.\n");
	}
}