#include <bits/stdc++.h>

using namespace std;

string in1, in2;
int len1, len2;
int opt[100][100];

int dp(int i, int j)
{
    if(i>=len1 || j>=len2) return 0;
    if(opt[i][j]!=-1) return opt[i][j];
    if(in1[i]==in2[j]) opt[i][j] = 1 + dp(i+1, j+1);
    else opt[i][j] = max(dp(i, j+1), dp(i+1, j));
    return opt[i][j];
}

int main()
{
    freopen("out.txt", "w", stdout);
    int i = 1;
    while(getline(cin, in1)){
        if(in1!="#") getline(cin, in2);
        else break;
        len1 = in1.size();
        len2 = in2.size();
        memset(opt, -1, sizeof(opt));
        printf("Case #%d: you can visit at most %d cities.\n", i++, dp(0,0));
    }
}
