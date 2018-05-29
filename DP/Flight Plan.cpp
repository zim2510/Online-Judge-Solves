#include <bits/stdc++.h>
#define min3(a, b, c) min(min(a,b), c)
#define MAX 1000000
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

using namespace std;

int wind[10][1000];
int opt[10][1000];
int n;

int dp(int hgt, int len){
	if(hgt==9 && len==n) return 0;
	if(len==n) return MAX;
	if(hgt>=10 || hgt<0) return MAX;
	if(opt[hgt][len]!=-1) return opt[hgt][len];
	opt[hgt][len] = min3(dp(hgt-1, len+1)+60, dp(hgt, len+1)+30, dp(hgt+1, len+1)+20) - wind[hgt][len];
	return opt[hgt][len];
}

int main()
{
    //READ();
	//WRITE();

    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        scanf("%d", &n);
        n /= 100;
        for(int i = 0; i<10; i++){
            for(int j = 0; j<n; j++){
                scanf("%d", &wind[i][j]);
            }
        }
        memset(opt, -1, sizeof(opt));
        printf("%d\n\n", dp(9, 0));
    }
}
