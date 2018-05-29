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
	Read();
	//Write();
	int tc;
	scanf("%d", &tc);

	TC(i, 1, tc){
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		queue <ii> left, right;
		FOR(i, 0, m){
			int time;
			string dir;
			cin>>time>>dir;
			if(dir=="left") left.push({i, time});
			else right.push({i, time});
		}

		int ctime = min(right.front().ss, left.front().ss), flag = 0;
		vector <ii> out;

		while(!left.empty() || !right.empty()){
			vector <int> loaded;
			while(left.size() && left.front().ss<=ctime && loaded.size()<n){
				loaded.pb(left.front().ff);
				left.pop();
			}
			for(int i = 0; i<loaded.size(); i++) out.pb({loaded[i], ctime+t});
			if(loaded.size() && !flag) ctime += t, flag = 1;
			else if(right.size() && !flag) ctime = max(ctime+t, right.front().ss+t), flag = 1;
			else if(!flag) ctime = left.front().ss;
			loaded.clear();


			while(right.size() && right.front().ss<=ctime && loaded.size()<n){
				loaded.pb(right.front().ff);
				right.pop();
			}
			for(int i = 0; i<loaded.size(); i++) out.pb({loaded[i], ctime+t});

			if(loaded.size() && flag) ctime += t, flag = 0;
			else if(left.size() && flag) ctime = max(ctime+t, left.front().ss+t), flag = 0;
			else if(flag) ctime = right.front().ss;
			loaded.clear();
		}
		sort(out.begin(), out.end());
		for(int i = 0; i<out.size(); i++) cout<<out[i].ss<<endl;
		if(i!=tc) printf("\n");
	}
}
