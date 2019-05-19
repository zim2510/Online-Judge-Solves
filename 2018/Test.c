#include<stdio.h>
#include<math.h>

int s[10000000], d[10000000];

int main()
{
    int t,a,i,n=10000000, j,l,f;

    int sq=sqrt(n);
    scanf("%d",&t);
    for(i=2; i<=n; i++)
        s[i]=i;

    for(i=4; i<=n; i+=2)
        s[i]=1;
    for(f=3; f<=sq; f+=2)
    {
        if(s[f]==f)
        {
            for(j=f*f; j<=n; j+=f)
                s[j]=1;
        }
    }
    int k=1;
    for(l=2; l<=n; l++)
    {
        if(s[l]!=1)
        {
            d[k]=s[l];
            k++;
        }
    }
    for(i=0; i<t; i++)
    {
        scanf("%d",&a);

        printf("%d\n",d[a]);
    }
    return 0;
}

