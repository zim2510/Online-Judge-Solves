#include <bits/stdc++.h>

using namespace std;

int k, n;

int check[100][100];

int dp(int h, int w, int lsf, int rsf)
{
	if((lsf==1 && rsf==0) || (rsf==1 && lsf==0)) return 1;
	if(check[lsf][rsf]!=-1) return check[lsf][rsf];
	if(h%k && w%k) return 0;
	printf("There are %dX%d grid. KX1=%d 1XK=%d\n", h, w, rsf, lsf);
	int result = 0;
	check[lsf][rsf] = 0;
	if(h%k==0){
		for(int i = 1; i<=w; i++){
			result = dp(h, w-i, lsf, rsf-1);
		}
	}
	if(w%k==0){
		printf("HERE\n");
		for(int i = 1; i<=h; i++){
			result = dp(h-i, w, lsf-1, rsf);
		}
	}
	check[lsf][rsf] = result;
	return result;

}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		memset(check, -1, sizeof(check));
		int cnt;
		scanf("%d %d", &k, &n);
		cnt = dp(k, n, 0, n);
		printf("%d\n", cnt);
	}
}