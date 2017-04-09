#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int calc(int n,std::string s)
{
if(n < 0)
	return 0;

if( n == 0 )
{
	int ret=0;
	try {
	ret= stoi(s);
	}
	catch(...)
	{
	return 0;
	}
	return ret;
}

int v[6];
v[0] = calc(n-6,s+"9");
v[1] = calc(n-7,s+"8");
v[2] = calc(n-3,s+"7");
v[3] = calc(n-5,s+"5");
v[4] = calc(n-4,s+"4");
v[5] = calc(n-2,s+"1");

return *max_element(std::begin(v),std::end(v));


}


int main()
{
	int n;
	cin>>n;
	std::string s="";
	cout<<calc(n,s);
	return 0;
}
