#include <bits/stdc++.h>

using namespace std;

string in1, in2;
int len1, len2;
int opt[1001][1001];

int dp(int i, int j)
{
    if(opt[i][j]!=-1) return opt[i][j];
    if(i>=len1 || j>=len2) return 0;
    if(in1[i]==in2[j]) opt[i][j] = 1 + dp(i+1, j+1);
    else opt[i][j] = max(dp(i, j+1), dp(i+1, j));
    return opt[i][j];
}

int main()
{
    while(getline(cin, in1) && getline(cin, in2)){
        len1 = in1.size();
        len2 = in2.size();
        memset(opt, -1, sizeof(opt));
        printf("%d\n", dp(0,0));
    }
}
