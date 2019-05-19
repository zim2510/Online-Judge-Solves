#include <stdio.h>
#include <malloc.h>


struct queue
{
	int * q;
	int sz = 0, frnt = 0, MX;
	
	queue(int mx){
		q = (int*) malloc(mx*sizeof(int));
		MX = mx;
	}

	void push(int data){
		if(sz<MX){
			q[(frnt+sz)%MX] = data;
			sz++;
		}
		//else printf("FULL\n");
	}

	void pop(){
		if(sz){
			frnt++;
			frnt %= MX;
			sz--;
		}
	}

	int front(){
		if(sz) return q[frnt];
	}

	int empty(){
		return sz==0;
	}
};

int graph[50][50];

void BFS(int source, int node)
{
	int dis[node];
	for(int i = 0; i<node; i++) dis[i] = -1;

	queue x(node);
	x.push(source);

	dis[source] = 0;
	while(!x.empty()){
		int cur = x.front();
		printf("%d\n", cur);
		for(int i = 0; i<node; i++){
			if(graph[cur][i] && dis[i]==-1){
				dis[i] = dis[cur] + 1;
				x.push(i);
			}
		}
		x.pop();
	}
	for(int i = 0; i<node; i++) printf("From %d to %d: %d\n", source+1, i+1, dis[i]);
}

int main()
{
	freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
	while(tc--){
		int node;
		scanf("%d", &node);
		for(int i = 0; i<node; i++){
			for(int j = 0; j<node; j++){
				scanf("%d", &graph[i][j]);
			}
		}
		for(int i = 0; i<node; i++){
			BFS(i, node);
		}
	}
}