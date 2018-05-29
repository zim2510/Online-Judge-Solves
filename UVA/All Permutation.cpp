#include <bits/stdc++.h>

using namespace std;

int mark[6];
int nums[6];

int cnt = 0;

void btrack(int pos)
{
	
	if(pos==6){
		for(int i = 0; i<6; i++) printf("%d ", nums[i]);
		printf("\n");
		cnt++;
		return;
	}

	for(int i = 0; i<6; i++){
		if(!mark[i]){
			mark[i] = 1;
			nums[pos] = i;
			btrack(pos+1);
			mark[i] = 0;
			if(cnt==10) return;
		}
	}
}

int main()
{
	freopen("out.txt", "w", stdout);
	btrack(0);
}