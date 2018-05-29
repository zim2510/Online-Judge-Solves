#include <bits/stdc++.h>

using namespace std;
int r, c;
int cnt = 0;
int sol[9];
int brd[9][9];

void btrack(int col)
{
    if(col==9){
        printf("%2d     ", ++cnt);
        for(int i = 1; i<col; i++) printf(" %d", sol[i]);
        printf("\n");
        return;
    }

    if(col==c){
        sol[col] = r;
        btrack(col+1);
        return;
    }

    for(int i = 1; i<9; i++){
        if(brd[i][col] == 0){
            sol[col] = i;
            for(int x = 1; x<9; x++){
                brd[i][x]++;
                if(i-x>0){
                    brd[i-x][col]++;
                    if(col+x<9) brd[i-x][col+x]++;
                    if(col-x>0) brd[i-x][col-x]++;
                }
                if(i+x<9){
                    brd[i+x][col]++;
                    if(col+x<9) brd[i+x][col+x]++;
                    if(col-x>0) brd[i+x][col-x]++;
                }
            }

            btrack(col+1);

            sol[col] = 0;
            for(int x = 1; x<9; x++){
                brd[i][x]--;
                if(i-x>0){
                    brd[i-x][col]--;
                    if(col+x<9) brd[i-x][col+x]--;
                    if(col-x>0) brd[i-x][col-x]--;
                }
                if(i+x<9){
                    brd[i+x][col]--;
                    if(col+x<9) brd[i+x][col+x]--;
                    if(col-x>0) brd[i+x][col-x]--;
                }
            }
        }
    }
}


int main()
{
    //freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        scanf("%d %d", &r, &c);
        if(i>0) printf("\n");
        for(int i = 1; i<9; i++){
            brd[r][i] = 1;
            if(r-i>0){
                brd[r-i][c] = 1;
                if(c+i<9) brd[r-i][c+i] = 1;
                if(c-i>0) brd[r-i][c-i] = 1;
            }
            if(r+i<9){
                brd[r+i][c] = 1;
                if(c+i<9) brd[r+i][c+i] = 1;
                if(c-i>0) brd[r+i][c-i] = 1;
            }
        }
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        cnt = 0;
        btrack(1);
        for(int i = 1; i<9; i++){
            brd[r][i] = 0;
            if(r-i>0){
                brd[r-i][c] = 0;
                if(c+i<9) brd[r-i][c+i] = 0;
                if(c-i>0) brd[r-i][c-i] = 0;
            }
            if(r+i<9){
                brd[r+i][c] = 0;
                if(c+i<9) brd[r+i][c+i] = 0;
                if(c-i>0) brd[r+i][c-i] = 0;
            }
        }
    }
}
