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

bool pCheck(string x)
{
    for(int i = 0; i<x.size(); i++){
        if(valid(x[i], 'a', 'z')) return 0;
    }
    return 1;
}

bool cmp(pair<int, string> x, pair<int, string> y)
{
    if(x.ff!=y.ff) return x.ff>y.ff;
    else return x.ss<y.ss;
}

int main(int argc, char const *argv[])
{
	Read();
    Write();
 	
 	while(true){
        string x;
        bool graph[105][10005];
        MEM(graph, 0);
        bool multiplier[10005];
        MEM(multiplier, 0);
        int pid = 0, uid = 0;
        map <string, int> user;
        vector<string> projects;
        vector <pair<int, string> > out;

        while(getline(cin, x)){
            if(x=="1") break;
            if(x=="0") return 0;
            if(pCheck(x)){
                projects.pb(x);
                //cout<<endl<<pid<<" "<<x<<endl;
                pid++;
            }
            else{
                if(user.find(x)==user.end()){
                    user[x] = uid++;
                }
                graph[pid-1][user[x]] = 1;
            }
        }
        for(int i = 0; i<uid; i++){
            int cnt = 0;
            for(int j = 0; j<pid; j++){
                cnt += graph[j][i];
            }
            multiplier[i] = (cnt<=1);
        }


        for(int i = 0; i<pid; i++){
            int cnt = 0;
            for(int j = 0; j<uid; j++){
                cnt += (graph[i][j])*multiplier[j];
            }
            out.pb({cnt, projects[i]});
            //cout<<" "<<cnt<<endl;
        }

        sort(out.begin(), out.end(), cmp);
        //cout<<out.size()<<endl;
        //for(int i = 0; i<out.size(); i++) cout<<out[i].ff<<" "<<out[i].ss<<endl;
        for(int i = 0; i<out.size(); i++){
            printf("%s %d\n", out[i].ss.c_str(), out[i].ff);
        }
    }

}