#include <bits/stdc++.h>

using namespace std;

char in1[500011], in2[500011];
int l1, l2;


int check(int x)
{
	int l = 0;
	for(int i = 0; i<l1; i++){
		int n = 0;
		for(int j = l; j<l2; j++){
			if(in2[j]==in1[i]){
				n++;
				if(n==x){l = j + 1; break;}
			}
		}
		if(n!=x) return 0;
	}
	return 1;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);

	for(int i = 1; i<=tc; i++){
		scanf(" %s %s", in1, in2);
		l1 = strlen(in1);
		l2 = strlen(in2);
		int l = 0, h = l2, mid, ans = 0;
		while(l<=h){
			//printf("%d %d\n", l, h);
			mid = (l+h)/2;
			//printf("MID: %d\n", mid);
			int x = check(mid);
			//printf("P: %d\n", x);
			if(x) l = mid + 1, ans = mid;
			else h = mid - 1;
			//printf("N%d %d\n", l, h);
		}
		printf("%d\n", ans);
	}
}