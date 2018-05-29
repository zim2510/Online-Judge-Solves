#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        char name[100000];
        scanf(" %[^\n]", name);
        int len = strlen(name);
        printf("%d\n", len);
        printf("%s\n", name);
    }
    return 0;
}
