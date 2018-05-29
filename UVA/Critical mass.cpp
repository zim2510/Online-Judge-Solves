#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	string a = "312931303130313130313031312831303130313130313031";
	cout<<a.size()/2;
	/*while(scanf("%d", &n)==1){
		int sum = (n*(n+1))/2;
		int diff, realdiff = abs((sum-sum/2)-sum/2);
		scanf("%d", &diff);
		if(diff!=realdiff) printf("ERROR\n");
		int nums, nsum = 0;
		scanf("%d", &nums);
		for(int i = 0; i<nums; i++){
			int t;
			scanf("%d", &t);
			nsum += t;
		}
		if(nsum!=sum/2 && nsum!=(sum-sum/2)) printf("ERROR");
		cout<<sum<<" "<<nsum<<" "<<diff<<" "<<realdiff<<endl;
	}*/
}