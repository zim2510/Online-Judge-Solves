#include <stdio.h>


int main()
{
    int input, year, month, day, hour, minute;
    int i, j;

    scanf("%d", &i);
    getchar();

    for(j=1; j<=i; j++){
        scanf("%d", &input);

        printf("Case %d:", j);

        for(year=0; input>=360*86400; year++){
            input=input-360*86400;
        }
        if(year>0) printf(" %d year", year);
        if(year>1) printf("s");

        for(month=0; input>=30*86400; month++){
            input=input-30*86400;
        }
        if(month>0) printf(" %d month", month);
        if(month>1) printf("s");

        for(day=0; input>=86400; day++){
            input=input-86400;
        }
        if(day>0) printf(" %d day", day);
        if(day>1) printf("s");

        for(hour=0; input>=3600; hour++){
            input=input-3600;
        }
        if(hour>0) printf(" %d hour", hour);
        if(hour>1) printf("s");

        for(minute=0; input>=60; minute++){
            input=input-60;
        }
        if(minute>0) printf(" %d minute", minute);
        if(minute>1) printf("s");


        if(input>0) printf(" %d second", input);
        if(input>1) printf("s");

        printf("\n");


    }
    return 0;
}



