#include <bits/stdc++.h>

using namespace std;
int c1[2501], c2[2501], c3[2501], c4[2501];
int s1[6250001], s2[6250001];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d %d %d %d", &c1[i], &c2[i], &c3[i], &c4[i]);
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			s1[i*n+j] = c1[i] + c2[j];
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			s2[i*n+j] = c3[i] + c4[j];
		}
	}
	sort(s2, s2+n*n);
	int cnt = 0;
	for(int i = 0; i<n*n; i++){
		cnt+= upper_bound(s2, s2+n*n, 0-s1[i]) - lower_bound(s2, s2+n*n, 0-s1[i]);
	}
	printf("%d\n", cnt);
}