#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	system("cls");
	vector<int> oedge[1000], iedge[1000];
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		int from, to;
		scanf("%d %d", &from, &to);
		oedge[from].push_back(to);
		iedge[to].push_back(from);
	}
	for(int i = 0; i<1000; i++){
		if(!oedge[i].empty()){
			printf("Connected with %d:", i);
			for(int j = 0; j<oedge[i].size(); j++){
				printf(" %d", oedge[i][j]);
			}
			printf("\n");
		}
		if(oedge[i].size()) printf("Out degree of %d: %d\n", i, oedge[i].size());
		if(iedge[i].size()) printf("In degree of %d: %d\n", i, iedge[i].size());
	}
	return 0;
}
