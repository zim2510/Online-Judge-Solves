#include <iostream>

using namespace std;


int main()
{
    int i;
    cin>>i;

    for(int coun=1;coun<=i; coun++){
        if(i>25) break;
        int input;
        cin>>input;
        cout<<"Case "<<coun<<": ";
            if(input>79) cout<<"A+"<<endl;
            else if(input>74 && input<80) cout<<"A"<<endl;
            else if(input>69 && input<75) cout<<"A-"<<endl;
            else if(input>64&&input<70) cout<<"B+"<<endl;
            else if(input>59&&input<65) cout<<"B"<<endl;
            else if(input>54&&input<60) cout<<"B-"<<endl;
            else if(input>49&&input<55) cout<<"C"<<endl;
            else if(input>44&&input<50) cout<<"D"<<endl;
            else if(input<45) cout<<"F"<<endl;

    }

return 0;
}
