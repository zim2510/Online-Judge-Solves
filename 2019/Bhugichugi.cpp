#include <stdio.h>

char keywords[][20] = {"for", "if", "while", "else", "do"};


bool find(char * haystack, char * needle)
{
	int i, j;

	for(i = 0; haystack[i]!=0; i++){
		for(j = 0; needle[j]!=0; j++){
			if(haystack[i+j]!=needle[j]) break;
		}
		if(!needle[j]){
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char haystack[10000];
	scanf(" %[^\n]", haystack);
	for(int i = 0; i<5; i++){
		if(find(haystack, keywords[i])) printf("%s\n", keywords[i]);
	}
}