#include <bits/stdc++.h>

using namespace std;
void btrack(int n, int b, int c);
char out[17];

int main()
{
    freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        if(i != 1) printf("\n");
        int n, b;
        scanf("%d %d", &n, &b);
        for(int i = 0; i<n; i++) out[i] = '0';
        out[n] = '\0';
        btrack(n, b, n - b);
    }
}

void btrack(int n, int b, int c)
{
    //printf("Entering: %d %d %d\n", n, b, c);
    if(!b) {printf("%s\n", out); return;}
    out[c] = '1';
    btrack(n, b-1, n - (b - 1));
    out[c] = '0';
    if(out[c-1] != '1' && c-1>=0) btrack(n, b, c - 1);
    //printf("Exiting\n");
    return;

}
