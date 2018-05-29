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
	Write();
	int tc;
	cin>>tc;
	TC(i, 1, tc){
		int n, q, id = 1;
		sf("%d %d", &n, &q);
		vector <vi> graph(100000);
		map <string, int> IDs;

		FOR(i, 0, n+1){
			string x;
			vector <string> names;
			getline(cin, x);
			int wordStart = 0, cnt = 0;
			string tmp = "";
			
			for(int i = 0; i<x.size(); i++){
				if(isalpha(x[i])) wordStart = 1;
				if(x[i]==',' || x[i]==':') cnt++;
				if(cnt==2){
					names.pb(tmp);
					if(!IDs[tmp]){
						 IDs[tmp] = id++;
					}
					cnt = 0;
					wordStart = 0;
					tmp = "";
				}
				if(wordStart){
					tmp += x[i];
				}
			}
			for(int i = 0; i<names.size(); i++){
				for(int j = 0; j<names.size(); j++){
					if(i!=j){
						graph[IDs[names[i]]].pb(IDs[names[j]]);
						graph[IDs[names[j]]].pb(IDs[names[i]]);
					}
				}
			}
		}

		vector <int> dis(id, -1);
		queue <int> Q;
		Q.push(IDs["Erdos, P."]);
		dis[IDs["Erdos, P."]] = 0;

		while(!Q.empty()){
			int now = Q.front();
			for(int i = 0; i<graph[now].size(); i++){
				if(dis[graph[now][i]]==-1){
					dis[graph[now][i]] = dis[now] + 1;
					Q.push(graph[now][i]);
				}
			}
			Q.pop();
		}

		cout<<"Scenario "<<i<<endl;
		FOR(i, 0, q){
			string name;
			getline(cin, name);
			cout<<name;
			int res = dis[IDs[name]];
			if(res==-1) cout<<" infinity"<<endl;
			else cout<<" "<<res<<endl;
		}
	}
}