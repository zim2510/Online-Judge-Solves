#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int line, i;
    char ara[101];
    cin>>line;

    for(int coun=1;coun<=line; coun++){
        cin>>ara;
        i=strlen(ara);
        if((int)ara[i-1]%2==0) cout<<"even"<<endl;
        else cout<<"odd"<<endl;

    }

return 0;
}
