#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	vector <int> s1(n), s2(n);
	for(int i = 0; i<n; i++) scanf("%d", &s1[i]);
	for(int i = 0; i<n; i++) scanf("%d", &s2[i]);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int s1e = n-1, s1i = 0, s2e = n-1, s2i = 0;
	int mx1 = s1[n-1];
	int mx2 = s2[n-1];
	int min = mx1 + mx2;
	if(n==2) {k *= 2; min = INT_MAX;}
	for(int i = 0; i<k && i<n/2; i++){
		if(max(s2[s2e-1], s1[s1i]) + max(mx1, s2[s2e]) < max(s1[s1e-1], s2[s2i]) + max(mx2, s1[s1e])){
			mx1 = max(mx1, s2[s2e]);
			mx2 = max(s2[s2e-1], s1[s1i]);
			int temp = mx1 + mx2;
			swap(s2[s2e], s1[s1i]);
			s2e--;
			s1i++;
			if(temp<min) min = temp;
		}
		else{
			mx2 = max(mx2, s1[s1e]);
			mx1 = max(s1[s1e-1], s2[s2i]);
			int temp = mx1 + mx2;
			swap(s1[s1e], s2[s2i]);
			s1e--;
			s2i++;
			if(temp<min) min = temp;
			//printf("2: %d\n", min);
		}
		/*for(int i = 0; i<n; i++) printf("%d ", s1[i]);
		printf("\n");
		for(int i = 0; i<n; i++) printf("%d ", s2[i]);
		printf("\n");*/
	}
	printf("%d\n", min);
}