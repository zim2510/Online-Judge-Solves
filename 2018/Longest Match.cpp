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

int opt[1005][1005];
vector <string> in[2];

void parse(string x, int index)
{
	in[index].clear();
	int wordstart = 0;
	string word;
	for(int i = 0; i<x.size(); i++){
		if(!wordstart){
			if(valid(x[i], 'a', 'z') || valid(x[i], 'A', 'Z') || valid(x[i], '0', '9')){
				wordstart = 1;
				word += x[i];
			}
		}
		else if(wordstart){
			if(valid(x[i], 'a', 'z') || valid(x[i], 'A', 'Z') || valid(x[i], '0', '9')){
				word += x[i];
			}
			else{
				in[index].pb(word);
				word.clear();
				wordstart = 0;
			}
		}

		if(i==x.size()-1 && word.size()){
			in[index].pb(word);
			word.clear();
		}
	}
}

int dp(int i, int j)
{
	if(i>=in[0].size() || j>=in[1].size()) return 0;

	if(opt[i][j]!=-1) return opt[i][j];

	opt[i][j] = max(dp(i+1, j), dp(i, j+1));
	if(in[0][i]==in[1][j]){
		opt[i][j] = max(1+dp(i+1, j+1), opt[i][j]);
	}
	return opt[i][j];
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc = 0;
	string x, y;
	while(getline(cin, x) && getline(cin, y)){
		printf("%2d. ", ++tc);
		if(x.size()==0 || y.size()==0){
			cout<<"Blank!"<<endl;
			continue;
		}
		parse(x, 0);
		parse(y, 1);
		MEM(opt, -1);
		int res = dp(0, 0);
		cout<<"Length of longest match: "<<res<<endl;
	}
}
