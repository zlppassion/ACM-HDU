#include <iostream>

using namespace std;

int main()
{
    double x,y,a;
    cin>>x>>y>>a;
    double xue=(x+y)*(1-a*0.01);
    double zi=x+y*1.0/2;
    if(zi<=xue)
        cout<<"By myself"<<endl;
    else
        cout<<"Through school"<<endl;

    return 0;
}
