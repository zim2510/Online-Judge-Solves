#include <iostream>
using namespace std;



int main()
{
    int lines, i, a;

    cin>>lines;

    for(i=0; i<lines; i++){
        cin>>a;
        if(a%2==0)cout<<"even"<<endl;
        else cout<<"odd"<<endl;
   }

    return 0;
}

