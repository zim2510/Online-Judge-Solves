#include <bits/stdc++.h>

using namespace std;

int nums[10000005], len[10000005], prv[10000005], path[10000005];

void pfind(int whr, int index){
	if(index==0) return;
	path[index-1] = nums[whr];
	pfind(prv[whr], index-1);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);
	cin.ignore();
	cin.ignore();

	for(int i = 0; i<tc; i++){
		if(i!=0) printf("\n");
		string s;
		int n = 0, mx = 1, last = 0;
		while(getline(cin, s)){
			if(s.size()==0) break;
			stringstream in(s);
			in>>nums[n++];
		}
		for(int i = 0; i<n; i++){
			len[i] = 1;
			for(int j = i; j>=0; j--){
				if(nums[j]<nums[i]){
					if(len[j]+1>len[i]){
						len[i] = len[j] + 1;
						prv[i] = j;
						if(len[i]>mx){
							mx = len[i];
							last = i;
						}
					}
				}
			}
		}
		pfind(last, mx);
		printf("Max hits: %d\n", mx);
		for(int i = 0; i<mx; i++) printf("%d\n", path[i]);
	}
	
}
