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

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	getchar();
	getchar();

	while(tc--){
		int id = 0;
		double tcnt = 0;
		vector <pair<string, double> > cnt(1);
		map <string, int> mp;
		while(true){
			string x;
			getline(cin, x);
			if(x=="") break;
			if(mp[x]) cnt[mp[x]].ss+=1;
			else {mp[x] = ++id; cnt.pb({x, 1});}
			tcnt+=1;
		}
		sort(cnt.begin()+1, cnt.end());
		for(int i = 1; i<=id; i++){
			printf("%s %d\n", cnt[i].ff.c_str(), (cnt[i].ss/tcnt)*100);
		}
		if(tc) cout<<endl;
	}
}