//This is how we use shortcomings in our favour. Guess where?
#include <stdio.h>

int main()
{
    int lines,i,students,temp;
    double input,result;


    scanf("%d", &lines);
    for(i=0;i<lines;i++){

        scanf("%d", &students);
        result=0;
        for(temp=0;temp<students;temp++){
            scanf("%lf", &input);
            result=result+input;
        }
        result=result/students;
        printf("%0.2lf\n", result);
    }

    return 0;
}
