#include<iostream>
#include<algorithm>
#include <vector>
#include<cstring>
//#include<string.h>
#include<ctype.h>
//#include<math.h>
//#include<stdlib.h>
//#include<stdio.h>
using namespace std;
void fun();
int main()
{
	fun();
	return 0;
}
void fun()
{
	char str0[100],str1[100],dest[100];
	cin>>str0;
	cin>>str1;
	if(!strcmp(str0,str1))
		cout<<str1<<endl;
	else
	{
		memset(dest,'\0',sizeof(dest));
		int i,j,n,length=0,end=0,arr[100][100];
		for(i=0;str0[i];i++)
		{
			for(j=0;str1[j];j++)
			{
				n = (i - 1 >= 0 && j - 1 >= 0) ? arr[i - 1][ j - 1] : 0;
				arr[i][j] = str0[i] == str1[j] ? 1 + n : 0;
				if (arr[i][j] > length)
				{
					length = arr[i][j];
					end = i;
				}
			}
		}
		if(length==0)
			cout<<"false"<<endl;
		else
		{
			strncpy(dest,&str0[end - length + 1],length);
			cout<<dest<<endl;
		}
	}

}
