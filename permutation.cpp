#include <iostream>
#include <algorithm>
#include <unistd.h>
using namespace std;


char a[] = "abcdefghijk";
int size = (sizeof(a)/sizeof(a[0]))-2;

void permute(int i)
{
	//cout<<"permute:"<<i<<endl;
	if( i == size)
	{
		cout<<a<<std::endl;
		return;
	}
	else
	{
		for(int j=i;j<=size;j++)
		{
			swap(a[i],a[j]);
			permute(i+1);
			swap(a[i],a[j]);
		}
	}

}
int main()
{
	permute(0);
	return 0;
}
