#include <stdio.h>
#include <malloc.h>

char word[150][300];
char cur[100000];
int n;

void print(int depth, int sp, char * rule)
{
	if(rule[depth] == '\0'){
		cur[sp] = '\0';
		printf("%s\n", cur);
		return;
	}

	if(rule[depth]=='0'){
		for(int i = 0; i<=9; i++){
			cur[sp] = '0' + i;
			print(depth+1, sp+1, rule);
		}
	}

	else if(rule[depth]=='#'){
		for(int i = 0; i<n; i++){
			int x = 0;
			while(word[i][x]!='\0'){
				cur[sp+x] = word[i][x];
				x++;
			}
			print(depth+1, sp+x, rule);
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(scanf("%d", &n)==1){
		printf("--\n");
		for(int i = 0; i<n; i++){
			scanf(" %s", word[i]);
		}
		int rules;
		scanf("%d", &rules);
		for(int i = 0; i<rules; i++){
			char rule[300];
			scanf(" %s", rule);
			print(0, 0, rule);
		}
	}
}