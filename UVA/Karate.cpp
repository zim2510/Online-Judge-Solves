#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    int str[50], ostr[50];

    for(int i = 1; i<=tc; i++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i<n; i++) scanf("%d", &str[i]);
        for(int i = 0; i<n; i++) scanf("%d", &ostr[i]);



        int cnt = 0;

        sort(str, str+n);
        sort(ostr, ostr+n, greater<int>());


        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(str[i]>ostr[j] && ostr[j]>=0){
                    cnt += 2;
                    str[i] = -1;
                    ostr[j] = -1;
                    break;
                }
            }
        }


        sort(str, str+n, greater<int>());
        sort(ostr, ostr+n, greater<int>());


        int ms = 0, os = 0;
        while(str[ms]!=-1 && ostr[os]!=-1){
            if(str[ms]==ostr[os]) {cnt += 1; str[ms] = -1; ostr[os] = -1; ms++; os++;}
            else os++;
        }

        printf("Case %d: %d\n", i, cnt);
    }
}
