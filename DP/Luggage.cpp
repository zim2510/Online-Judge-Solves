#include <bits/stdc++.h>

using namespace std;

int wgt[20], opt[21][201], n;


int dp(int wsf, int ci)
{
	if(wsf==0) return 1;
	if(ci>=n) return 0;
	if(opt[ci][wsf]!=-1) return opt[ci][wsf];
	opt[ci][wsf] = dp(wsf-wgt[ci], ci+1) + dp(wsf, ci+1);
	return opt[ci][wsf];
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);
	cin.ignore();
	for(int i = 1; i<=tc; i++){
		memset(opt, -1, sizeof(opt));
		string s;
		int p;
		getline(cin, s);
		stringstream ss(s);
		int tmp;
		n = 0;
		int total = 0;
		while(ss>>tmp){
			wgt[n++] = tmp;
			total += tmp;
		}
		if(total%2) printf("NO\n");
		else{
			p = dp(total/2, 0);
			if(p==0) printf("NO\n");
			else printf("YES\n");
		}
	}
}