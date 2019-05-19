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

string lower(string x)
{
	string ret;

	for(int i = 0; i<x.size(); i++){
		if(valid(x[i], 'A', 'Z')) x[i] = x[i] - 'A' + 'a';

		if(valid(x[i], 'a', 'z')) ret += x[i];
		else ret += ' ';
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int n, k, tc = 1;
	while(sf("%d %d ", &n, &k)==2){
		map <string, bool> M;
		FOR(i, 0, n){
			string t;
			getline(cin, t);
			M[lower(t)] = true;
		}

		vector <int> score(k);
		vector <string> excuses;
		int mx = 0;

		FOR(i, 0, k){
			string x;
			getline(cin, x);
			excuses.pb(x);

			stringstream S(lower(x));
			string t;

			while(S>>t){
				score[i] += M[t];
			}
			if(score[i]>mx) mx = score[i];
		}

		cout<<"Excuse Set #"<<tc++<<endl;
		for(int i = 0; i<k; i++){
			if(score[i]==mx) cout<<excuses[i]<<endl;
		} cout<<endl;
	}
}
