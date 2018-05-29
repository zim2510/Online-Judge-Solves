#include <bits/stdc++.h>

using namespace std;

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))
#define sz(a) 			  int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               1000000000

int grid[8][8];
vector <int> v(8);
int x, y, counter;

void doblock(int x, int y)
{
    for(int i = 1; i<8; i++){
        if(x+i<=7 && y+i<=7) grid[x+i][y+i] -= 1;
        if(x+i<=7 && y-i>=0) grid[x+i][y-i] -= 1;
        if(y+i<=7) grid[x][y+i] -= 1;
        if(y-i>=0) grid[x][y-i] -= 1;
        if(x-i>=0 && y+i<=7) grid[x-i][y+i] -= 1;
        if(x-i>=0 && y-i>=0) grid[x-i][y-i] -= 1;
        if(x+i<=7) grid[x+i][y] -= 1;
        if(x-i>=0) grid[x-i][y] -= 1;
    }
}

void remblock(int x, int y)
{
    for(int i = 1; i<8; i++){
        if(x+i<=7 && y+i<=7) grid[x+i][y+i] += 1;
        if(x+i<=7 && y-i>=0) grid[x+i][y-i] += 1;
        if(y+i<=7) grid[x][y+i] += 1;
        if(y-i>=0) grid[x][y-i] += 1;
        if(x-i>=0 && y+i<=7) grid[x-i][y+i] += 1;
        if(x-i>=0 && y-i>=0) grid[x-i][y-i] += 1;
        if(x+i<=7) grid[x+i][y] += 1;
        if(x-i>=0) grid[x-i][y] += 1;
    }
}

int btrack(int row, int cnt)
{
    if(row==x) {btrack(row+1, cnt+1); return 0;}
    if(row==8){
        if(cnt==8){
            printf("%2d     ", ++counter);
            for(int i = 0; i<v.size(); i++) printf(" %d", v[i]+1);
            printf("\n");
        }
        return 0;
    }

    for(int i = 0; i<8; i++){
        if(grid[row][i]==0){
            doblock(row, i);
            v[row] = i;
            btrack(row+1, cnt+1);
            remblock(row, i);
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        if(i) printf("\n");
        scanf("%d %d", &y, &x);
        x--, y--;
        memset(grid, 0, sizeof(grid));
        counter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        doblock(x, y);
        v[x] = y;
        btrack(0, 0);
    }
}
