#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size()) 
#define all(c)            (c).begin(),(c).end() 
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               1000000000
#define sf             	  scanf
#define pf 	              printf
#define ll 				  long long
#define ull               unsigned long long

using namespace std;

char ar[5][5];
int n, used[17], grid[5][5], mx = 0;

bool val(int x, int y){
	
	for(int i = y - 1; i >= 1; i--){
		printf("1\n");
		if(grid[x][i] == 5 || y == 1) break;
		if(grid[x][i] == 1) return false;
	}

	for(int i = y + 1; i <= n; i++){
		printf("2\n");
		if(grid[x][i] == 5 || y == n) break;
		if(grid[x][i] == 1) return false;
	}

	for(int i = x - 1; i >= 1; i--){
		printf("3\n");
		if(grid[i][y] == 5 || x == 1) break;
		if(grid[i][y] == 1) return false;
	}

	for(int i = x + 1; i <= n; i++){
		printf("4\n");
		if(grid[i][y] == 5) break;
		if(grid[i][y] == 1) return false;
	}

	return true;
}



void bt(int pos){
	if(pos == (n*n) + 1){
		int x = 1, y = 1;
		for(int i = 1; i <= n*n; i++){
			 if(ar[x][y] == '.') grid[x][y] = used[i];
			 else grid[x][y] = 5;
			 y++;
			 if(i % n == 0 && i > 1){
				x++;
				y = 1;
			}
		}

		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				printf("%d ", grid[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
		
		int ct = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				//printf("%d", grid[i][j]);
				printf("Valid %d %d %d: %d\n", i, j, grid[i][j], val(i, j));
				if(grid[i][j] == 1 && val(i, j)) ct++;
				//else break;
			}
			//printf("\n");
		}
		//cout << ct << endl;
		mx = max(mx, ct);

		
		return;
	}
		used[pos] = 1;
		bt(pos+1);
		used[pos] = 0;
		bt(pos+1);
	
}



int main(){
	Read();
	Write();
		
	
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &ar[i][j]);
		}
	}

	bt(1);

	cout << mx << endl;

	return 0;
}