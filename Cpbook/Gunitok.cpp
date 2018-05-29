#include <iostream>

using namespace std;

void calculate(int a, int b);

int main()
{
    int a, b, line;
    cin>>line;

    for(int coun=1;coun<=line; coun++){
        if(line>100) break;
        int input;
        cin>>a>>b;
        cout<<"Case "<<coun<<":";
        calculate(a,b);


    }

return 0;
}

void calculate(int a,int b)
{
    int i;
    int j=0;
    for(int i=1;;i++){
        j=a*i;
        if(j<=b)cout<<" "<<j;
        else {
            cout<<endl;
            break;
        }
    }
}
