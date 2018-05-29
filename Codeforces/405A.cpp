#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int col[n];
    for(int i = 0; i<n; i++) scanf("%d", &col[i]);
    sort(col, col + n);
    for(int i = 0; i<n; i++){
        printf("%d", col[i]);
        if(i != n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
