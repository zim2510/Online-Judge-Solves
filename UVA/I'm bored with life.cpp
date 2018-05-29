#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int x, y;
	scanf("%d %d", &x, &y);
	x = min(x, y);
	y = 1;
	for(int i = 2; i<=x; i++){
		y *= i;
	}
	printf("%d\n", y);
	return 0;
}