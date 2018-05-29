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
#define sz(a)             int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

const int sz = 9;

char brd[sz][sz];
int row[sz][sz];
int col[sz][sz];
int blk[sz][sz];

struct prior
{
    int val;
    int pos;
};

prior vals[sz*sz];
int last = 0;

inline int blkcalc(int i, int j){
    return (3*(i/3)+j/3);
}

bool cmp(prior a, prior b){
    return a.val>b.val;
}

void backtrack(int ci, int cnt)
{
    int x = vals[ci].pos;
    int m = x/sz;
    int n = x - (m*sz);
    int b = blkcalc(m, n);
    if(ci==last){
        for(int i = 0; i<sz; i++){
            for(int j = 0; j<sz; j++){
                printf("%c", brd[i][j]);
            } printf("\n");
        }
    }

    for(int i = 0; i<sz; i++){
        if(!row[m][i] && !col[n][i] && !blk[b][i]){
            blk[b][i] = col[n][i] = row[m][i] = 1;
            brd[m][n] = '1' + i;
            backtrack(ci+1, cnt+1);
            blk[b][i] = col[n][i] = row[m][i] = 0;
            brd[m][n] = '.';
        }
    }
}


int main(int argc, char const *argv[])
{
    Read();
    Write();
    int tc;
    scanf("%d", &tc);
    TC(i, 1, tc){
        printf("Case %d:\n", i);
        MEM(row, 0);
        MEM(col, 0);
        MEM(blk, 0);
        FOR(i, 0, sz){
            FOR(j, 0, sz){
                scanf(" %c", &brd[i][j]);
                if(brd[i][j]!='.'){
                    row[i][brd[i][j]-'1'] = 1;
                    col[j][brd[i][j]-'1'] = 1;
                    blk[blkcalc(i, j)][brd[i][j]-'1'] = 1;
                }
            }
        }
        last = 0;
        FOR(i, 0, sz*sz){
            int x = i/sz;
            int y = i - x*sz;
            int b = blkcalc(x, y);
            vals[i].pos = i;
            vals[i].val = 0;
            if(brd[x][y]!='.') continue;
            last++;
            TC(j, 1, sz){
                if(row[x][j] || col[y][j] || blk[b][j]){
                    vals[i].val++;
                }
            }
        }
        sort(vals, vals+sz*sz, cmp);
        backtrack(0, 0);
    }
}

/*30
 
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2.....85
...8.....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.......4.
..2....1.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46......
.3.1.....
.2..6..85
....7....
6...3...4
....14...
79..5..3.
.....2.4.
......61.

.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2.....85
...8.....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.......4.
..2....1.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46......
.3.1.....
.2..6..85
....7....
6...3...4
....14...
79..5..3.
.....2.4.
......61.

.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2.....85
...8.....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.......4.
..2....1.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.
.46......
.3.1.....
.2..6..85
....7....
6...3...4
....14...
79..5..3.
.....2.4.
......61.
*/