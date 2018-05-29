#include <bits/stdc++.h>
#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)

using namespace std;

01786280325

int main()
{
	//Read();
	//Write();
	int grid[100][100];
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	int sum = 0;
	for(int i = 0; i<n; i++){
		sum += grid[i][i];
	}
	printf("%d\n", sum);
}