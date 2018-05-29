#include <bits/stdc++.h>

using namespace std;


int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        char p[2001];
        int n;
        scanf("%d", &n);
        scanf(" %s", p);

        int m = 0;

        for(int i = 0; p[i]!='\0'; i++){
            m = (m*10 + (p[i] - '0'))%n;
        }
        printf("%d\n", m);
    }

   return 0;
}
