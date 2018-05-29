#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    getchar();

    for(int i = 0; i<tc; i++){
        char fld[101];
        int n, cnt = 0, sc = 0;
        scanf("%d", &n);
        getchar();
        scanf("%[^\n]", fld);

        for(int i = 0; i<n; i++){
            //printf("%c", fld[i]);
            if(fld[i]=='.') cnt++;
            if(cnt==2){
                sc++;
                i++;
                cnt = 0;
            }
            else if(cnt==1 &&(fld[i]=='#' || i == n - 1)){
                sc++;
                i++;
                cnt = 0;
            }
        }
        printf("Case %d: %d\n", i+1, sc);
    }
}
