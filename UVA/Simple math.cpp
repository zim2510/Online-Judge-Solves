#include <bits/stdc++.h>

int main()
{
	char in[10000];


	for(1){
		int wcnt = 0;
		int ws = 0;
		for(int i = 0; in[i]!= '\0'; i++){
			if(ws == 0 && ((in[i]>='a' && in[i]<='z') || (in[i]>='a' && in[i]<='z'))){
				ws = 1;
				wcnt++;
			}
			else if(!((in[i]>='a' && in[i]<='z') || (in[i]>='a' && in[i]<='z'))) ws = 0;
		}
		printf("%d\n", wcnt);
	}
}
