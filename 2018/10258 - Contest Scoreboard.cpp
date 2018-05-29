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
#define sf                scanf
#define pf                printf

const int dx[] = { 0, -1,  0,  1,        -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,         1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

struct team
{
    int teamno = 0;
    int solves = 0, penalty = 0, tsubmission = 0;
    int wrong[10];
    int solve[10];
};

bool cmp(team x, team y)
{
    if(x.solves!=y.solves){
        return x.solves>y.solves;
    }
    if(x.penalty!=y.penalty){
        return x.penalty<y.penalty;
    }
    return x.teamno<y.teamno;
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc, i = 0;
    string end;
    sf("%d", &tc);
    getline(cin, end);

    while(i++<=tc){
        vector <team> teams(101);
        while(true){
            string x;
            getline(cin, x);
            if(!x.size()) break;

            stringstream line(x);
            int teamno, probno, subt;
            char verdict;

            line>>teamno>>probno>>subt>>verdict;

            if(verdict=='C'){
                teams[teamno].teamno = teamno;
                teams[teamno].tsubmission++;
                if(teams[teamno].solve[probno]==0){
                    teams[teamno].solve[probno] = 1;
                    teams[teamno].solves++;
                    teams[teamno].penalty += subt + teams[teamno].wrong[probno] * 20;
                }
            }
            else if(verdict=='I'){
                teams[teamno].teamno = teamno;
                teams[teamno].tsubmission++;
                if(teams[teamno].solve[probno]==0){
                    teams[teamno].wrong[probno]++;
                }
            }
            else{
                teams[teamno].teamno = teamno;
                teams[teamno].tsubmission++;
            }
        }
        sort(teams.begin(), teams.end(), cmp);
        for(int i = 0; i<teams.size(); i++){
            if(teams[i].tsubmission > 0) printf("%d %d %d\n", teams[i].teamno, teams[i].solves, teams[i].penalty);
        }
        if(i!=1 && i!=tc+1) printf("\n");
    }
}