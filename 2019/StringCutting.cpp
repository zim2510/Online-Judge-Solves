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

bool check(int N,int pos)	{ return (bool)(N & (1<<pos)); }
int sset(int N,int pos)		{	return N=N | (1<<pos);	   }

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int tc;
	sf("%d", &tc);

	TC(i, 1, tc){
		int n, cost = 0;
		sf("%d", &n);
		vector <int> cuts(n);
		FOR(i, 0, n) sf("%d", &cuts[i]);

		string input;
		cin>>input;

		vector <bool> mark(input.size(), false);

		for(int i = 0; i<cuts.size(); i++){
			vector <char> part1, part2;
			for(int j = 0; j<input.size(); j++){
				if(j<cuts[i] && mark[j]) part1.clear();
				if(j<cuts[i]) part1.pb(input[j]);

				if(j>=cuts[i] && mark[j]) break;
				if(j>=cuts[i]) part2.pb(input[j]);
			}

			mark[cuts[i]] = true;

			sort(all(part1));
			part1.resize(unique(all(part1))-part1.begin());

			sort(all(part2));
			part2.resize(unique(all(part2))-part2.begin());

			vector <int> cnt(26, 0);

			FOR(i, 0, part1.size()) cnt[part1[i]-'a']++;
			FOR(i, 0, part2.size()) cnt[part2[i]-'a']++;

			FOR(i, 0, 26) cost += cnt[i]%2;
		}

		cout<<cost<<endl;
	}
}
