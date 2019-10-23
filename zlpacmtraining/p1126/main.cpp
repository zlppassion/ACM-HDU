#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int zhuan(int x)
{
    int num=0;
    while(x)
    {
        num+=x%10;
        x/=10;
    }
    return num;

}
int main()
{
    int a;
    scanf("%d",&a);

    for(int i=0;;i++)
    {
        int te=zhuan(a+i);
        if(te%4==0)
        {
            cout<<a+i<<endl;
            break;
        }
    }

   return 0;


}
