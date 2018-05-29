#include <bits/stdc++.h>
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
using namespace std;

int main()
{
    READ();
    WRITE();

    int n, m, f = 0;
    while(scanf("%d %d", &n, &m)==2){
    	int r = 1;
    	if(m!=0){
    		for(int i = n; i>(n-m); i--){
    			int x = i;
    			while(x%5==0){
    				x /= 5;
    				f++;
    			}
    			while(f && x%2==0){
    				x /= 2;
    				f--;
    			}
    			r *= x;
    			r = r%10;
    		}
    		while(f){
    			r /= 2;
    			f--;
    		}
	    }
    	printf("%d\n", r%10);
    }
}
