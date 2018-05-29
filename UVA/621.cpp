#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, len;
    string in;

    scanf("%d",&n);

    while(n--){
        cin>>in;
        len = in.size();
        if (in=="1" || in=="4" || in=="78") printf("+");
        else if (in[len-2]=='3' && in[len-1]=='5') printf("-");
        else if (in[0]=='9' && in[len-1]=='4') printf("*");
        else if (in[0]=='1' && in[1]=='9' && in[2]=='0') printf("?");
        printf("\n");
    }

    return 0;
}
