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


struct team
{
	int score = 0;
	string name;
	int goals = 0;
	int wins = 0;
	int loses = 0;
	int ties = 0;
	int igoals = 0;
	int games = 0;
};

bool cmp(team a, team b)
{
	if(a.score!=b.score) return a.score>b.score;
	if(a.wins!=b.wins) return a.wins>b.wins;
	if((a.goals-a.igoals)!=(b.goals-b.igoals)) return (a.goals-a.igoals)>(b.goals-b.igoals);
	if(a.goals!=b.goals) return a.goals>b.goals;
	if(a.games!=b.games) return a.games<b.games;
	string tmpa = a.name;
	string tmpb = b.name;
	transform(tmpa.begin(), tmpa.end(), tmpa.begin(), ::toupper);
	transform(tmpb.begin(), tmpb.end(), tmpb.begin(), ::toupper);
	return tmpa<tmpb;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	string hudai;
    getline(cin, hudai);

	TC(i, 1, tc){
		string tournament;
		getline(cin, tournament);

		int n;
		sf("%d", &n);
		getline(cin, hudai);

		vector <team> teams(n);
		map <string, int> mp;

		for(int i = 0, id = 0; i<n; i++){
			string name;
			getline(cin, name);
			mp[name] = id;
			teams[id].name = name;
			id++;
		}

		int m;
		scanf("%d", &m);
		getline(cin, hudai);

		FOR(i, 0, m){
			char tmp[100];
			string t1, t2;
			int s1, s2;
			scanf("%[^#]", tmp);
			t1 = tmp;
			scanf("#%d@%d#%[^\n]", &s1, &s2, tmp);
			t2 = tmp;
			getline(cin, hudai);

			int tf = mp[t1], tt = mp[t2];

			teams[tf].goals += s1;
			teams[tt].goals += s2;
			teams[tf].igoals += s2;
			teams[tt].igoals += s1;
			teams[tt].games += 1;
			teams[tf].games += 1;

			if(s1>s2) teams[tf].score += 3, teams[tf].wins++, teams[tt].loses++;
			else if(s1<s2) teams[tt].score += 3, teams[tt].wins++, teams[tf].loses++;
			else teams[tf].score += 1, teams[tt].score += 1, teams[tt].ties++, teams[tf].ties++;
		}

		sort(teams.begin(), teams.end(), cmp);
		cout<<tournament<<endl;
		for(int i = 0; i<teams.size(); i++){
			cout<<i+1<<") "<<teams[i].name<<" "<<teams[i].score<<"p, ";
			cout<<teams[i].games<<"g ("<<teams[i].wins<<"-"<<teams[i].ties<<"-"<<teams[i].loses<<"), ";
			cout<<teams[i].goals-teams[i].igoals<<"gd ("<<teams[i].goals<<"-"<<teams[i].igoals<<")"<<endl;
		}
		if(i!=tc) cout<<endl;
	}
}
