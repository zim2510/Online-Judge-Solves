#include <bits/stdc++.h>

using namespace std;

int color[50];
int graph[50][50];

void Union(int n, int m)
{
	int x = Find(n);
	int y = Find(m);
	color[x] = y;
}

bool Find(int n)
{
	if(color[n]==n) return n;
	else color[n] = Find(color[n]);
	return color[n];
}

int main()
{
	int n;
	scanf("%d", &nodes);
	FOR(i, 0, nodes) sets[i] = i; 
}