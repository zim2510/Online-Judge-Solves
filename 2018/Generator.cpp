#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("in.txt", "w", stdout);
	printf("5\n");
	for(int i = 0; i<5; i++){
		int n = rand()%100000 + 1, q = rand()%100000 + 1;
		printf("%d %d\n", n, q);
		vector <int> mark(n+1);
		int q1cnt = 0;
		for(int i = 0; i<q; i++){
			int qtype = rand()%2 + 1;
			if(q1cnt==n) qtype = 2;
			if(qtype==1){
				int x = rand()%n + 1;
				while(mark[x]){
					x = rand()%n + 1;
				}
				mark[x] = 1;
				printf("%d %d\n", qtype, x);
				q1cnt++;
			}
			else if(qtype==2){
				int l = rand()%n + 1, r = rand()%n + 1;
				if(l>r) swap(l, r);
				printf("%d %d %d\n", qtype, l, r);
			}
		}

	}
}