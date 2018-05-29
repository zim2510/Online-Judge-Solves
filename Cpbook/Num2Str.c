#include <stdio.h>
void tens(a1);
void simple(a1);
void ext(a1,a2,n);
void teen(a1);
int main()
{
    char cha[11], cha2[11];
    int a,b,c,d;
    printf("Num2String\nVersion:2.3\nAuthor:Muhaiminul Islam Zim.");
    printf("\n\nInstructions:\n-------------\nInput should be given in a simple manner.\nStrange input should  never be given.\nOtherwise, it may cause error.");
    while(1)
    {
        printf("\n\n\nPlease enter a number (Range: -99999999 to 99999999): ");
        gets(cha);
        printf("\n");
        a=0;
        b=strlen(cha);
        c=10-b;

        while(a<c){
            cha2[a]='n';
            a++;
        }

        for(c=0;a<10 && c<b;a++,c++){
            cha2[a]=cha[c];
        }

        cha2[a]='\0';
        b=strlen(cha2);

        for(a=0,c=1,d=0;a<b;a++){
            if(cha2[a]=='-'){
                printf("Minus");
                c=0;
            }
            if(cha2[a]!='n' && c==1 && cha2[a]!='0'){
                printf("Plus");
                c=0;
            }
            if((a==1 || a==3 || a==5 || a==8) && cha2[a]!='n'&& ((cha2[a]!='1' && a!=8)|| (cha2[a]!='1' && a!=3) || (cha2[a]!='1' && a!=5))){
                tens(cha2[a]);

            }
            if((cha2[a]=='1' && a==8) || (cha2[a]=='1' && a==3) || (cha2[a]=='1' && a==5)){
                d=1;
                teen(cha2[a+1]);
                }

            if((a==2 || a==4 || a==6 || a==9) && (cha2[a]!='n') && ((cha2[a-1]!='1' && a!=9)|| (cha2[a-1]!='1' && a!=4) || (cha2[a-1]!='1' && a!=6))){
                simple(cha2[a]);
            }
            if(a==7 && cha[2]!='n'){
                simple(cha2[a]);
            }
            if((a==2 || a==4 || a==6 || a==7) && (cha2[a]!='n')){
                ext(cha2[a],cha2[a-1],a);
            }
        }
        printf(".");
    }
    getch();




    return 0;
}
void tens(a1)
{
    if(a1=='1') printf("ten ");
    else if(a1=='2') printf(" twenty");
    else if(a1=='3') printf(" thirty");
    else if(a1=='4') printf(" forty");
    else if(a1=='5') printf(" fifty");
    else if(a1=='6') printf(" sixty");
    else if(a1=='7') printf(" seventy");
    else if(a1=='8') printf(" eighty");
    else if(a1=='9') printf(" ninety");
}
void simple(a1)
{
    if(a1=='1') printf(" one");
    else if(a1=='2') printf(" two");
    else if(a1=='3') printf(" three");
    else if(a1=='4') printf(" four");
    else if(a1=='5') printf(" five");
    else if(a1=='6') printf(" six");
    else if(a1=='7') printf(" seven");
    else if(a1=='8') printf(" eight");
    else if(a1=='9') printf(" nine");

}
void teen(a1)
{
    if(a1=='0') printf(" ten");
    else if(a1=='1') printf(" eleven");
    else if(a1=='2') printf(" twelve");
    else if(a1=='3') printf(" thirteen");
    else if(a1=='4') printf(" fourteen");
    else if(a1=='5') printf(" fifteen");
    else if(a1=='6') printf(" sixteen");
    else if(a1=='7') printf(" seventeen");
    else if(a1=='8') printf(" eighteen");
    else if(a1=='9') printf(" nineteen");
}

void ext(a1,a2,n)
{

    if(a1!='-' && a1!='+' && (a1!='0' || a2!='0') &&(a1!='0' || a2!='n') ){
        if(n==6) printf(" thousand");
        if(n==4) printf(" lac");
        if(n==2) printf(" crore");
    }
    if(a1!='-' && a1!='+' && (a1!='0')){
        if(n==7) printf(" hundred");
    }

}
