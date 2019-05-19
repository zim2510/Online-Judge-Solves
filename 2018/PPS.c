#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("out.txt", "w", stdout);

    int a = 100,i,c,b;
    printf("%p\"%d\"\n", a, a);
    char ch[100];
    while(scanf("%d",&a)==1){
       int ans=0;
       printf("Value of a: \"%d\"\n", a);
    	for(i=0;i<a;i++)	{
	        scanf("%d",&b);
	        printf("Value of b: %p\"%x\"\n", &b, &b);
	        gets(ch);
	        printf("Value of ch: \"%s\"\n", ch);
	        if(ch=="suco de laranja")
	        {
	            ans=ans+(b*120);
	        }
	        else if(ch=="morango fresco")
	        {
	            ans=ans+(b*85);
	        }
	        else if(ch=="mamao")
	        {
	            ans=ans+(b*85);
	        }
	        else if(ch=="goiaba vermelha")
	        {
	            ans=ans+(b*70);
	        }
	        else if(ch=="manga")
	        {
	            ans=ans+(b*56);
	        }
	        else if(ch=="laranja")
	        {
	            ans=ans+(b*50);
	        }
	        else if(ch=="brocolis")
	        {
	            ans=ans+(b*34);
	        }

    	}
	    printf("%d",ans);
	    
	    if(ans<110)
	    {
	        c=110-ans;
	        printf("Mais %d mg\n",c);
	    }
	    else if(ans>130)
	    {
	        c=ans-130;
	        printf("Menos %d mg\n",c);
	    }
	    else
	    {
	        printf("%d mg\n",ans);
	    }
	}

    return 0;
}
