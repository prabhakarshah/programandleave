#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isbalanced(string str){

	cout<<str;
	stack<char>  stk;

	int i=0;
	while( i< str.length() )
	{
		if( str[i] == ')' )
		{
			if(stk.empty()) 
			return false;

		stk.pop();
		
		}
		else if (str[i] == '(')
		stk.push('(');
		++i;	
	}
	cout<<stk.empty();
	return stk.empty() && (str.length() == i);
}

int main()
{
	string str;
	cin>>str;

	cout<<isbalanced(str);
	return 0;
}
