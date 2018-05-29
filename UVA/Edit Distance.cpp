#include <bits/stdc++.h>

using namespace std;

int cost[100][100], l1, l2;
char s1[101], s2[101];


int ed(int i, int j)
{
	if(i==l1) return abs(l2-j);
	if(j==l2) return abs(l1-i);
	if(cost[i][j]!=-1) return cost[i][j];
	int m;
	if(s1[i] == s2[j]) m = ed(i+1, j+1);
	else{
		m = ed(i+1, j+1) + 1;
		m = min(m, ed(i, j+1) + 1);
		m = min(m, ed(i+1, j) + 1);
	}
	cost[i][j] = m;
	return cost[i][j];
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	memset(cost, -1, sizeof(cost));
	scanf(" %s %s", s1, s2);
	//printf("%s %s\n", s1, s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	printf("%d\n", ed(0, 0));

}