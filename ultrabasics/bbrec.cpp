#include <iostream>
#include <stack>
#include <string>

using namespace std;

char match(string str, int i, int& pos){
	if( i ==  str.length() )
	{
		return '\0';
	}

	if( str[i] == ')'){
		pos = i;
		return str[i];
	}

	if( str[i] == '(')
	{
		char c = match( str, i+1, pos);
		if( c == ')')
		{
			return match(str, pos+1, pos);
		}
		return str[i];
	}
	return match(str, i+1, pos);
}
int main()
{
	string str;
	cin>>str;
	int x=0;
	cout<<('\0'==match(str,0,x));
	return 0;
}
