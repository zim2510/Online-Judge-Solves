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
 
using namespace std;
 
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;
 
inline int blkcalc(int i, int j){
    return (3*(i/3)+j/3);
}
 
vector <ii> pts;
char brd[9][9];
int col[9][9], row[9][9], blk[9][9], found;
 
 
 
bool heuristic(ii x, ii y)
{
    int xcnt = 0, ycnt = 0;
    int xblk = blkcalc(x.ff, x.ss), yblk = blkcalc(y.ff, y.ss);
    for(int i = 0; i<9; i++){
            if(row[x.ff][i] || col[x.ss][i] || blk[xblk][i]) xcnt++;
            if(row[y.ff][i] || col[y.ss][i] || blk[yblk][i]) ycnt++;
    }
    return xcnt>ycnt;
}
 
void solve(int ci)
{
    if(ci==pts.size()){
        printf("SOLUTION FOUND!\n");
        for(int i = 0; i<9; i++){
            if(i%3==0) printf("\n");
            for(int j = 0; j<9; j++){
                if(j%3==0) printf(" ");
                printf("%c", brd[i][j]);
            } printf("\n");
        }
        found = 1;
        return;
    }

    int iblk = blkcalc(pts[ci].ff, pts[ci].ss);
    
    for(int i = 0; i<9; i++){
        if(!row[pts[ci].ff][i] && !col[pts[ci].ss][i] && !blk[iblk][i]){
            row[pts[ci].ff][i] = col[pts[ci].ss][i] = blk[iblk][i] = 1;
            brd[pts[ci].ff][pts[ci].ss] = '1' + i;
            sort(pts.begin()+ci+1, pts.end(), heuristic);
            solve(ci+1);
            row[pts[ci].ff][i] = col[pts[ci].ss][i] = blk[iblk][i] = 0;
            if(found) return;
        }
    }
}
 
int main(int argc, char const *argv[])
{
    Read();
    Write();

    clock_t tStart = clock();

    pts.clear();
    MEM(row, 0);
    MEM(col, 0);
    MEM(blk, 0);
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            scanf(" %c", &brd[i][j]);
            if(brd[i][j]=='.') pts.pb({i, j});
            else{
                row[i][brd[i][j]-'1'] = 1;
                col[j][brd[i][j]-'1'] = 1;
                blk[blkcalc(i, j)][brd[i][j]-'1'] = 1;
            }
        }
    }

    found = 0;
    solve(0);
    if(!found) printf("There's no valid solution\n");
    printf("\n");

    printf("Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
}