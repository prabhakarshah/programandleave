//Permutaion of a given string
//Pointers: https://introcs.cs.princeton.edu/java/23recursion/Permutations.java.html
#include <string>

#include <iostream>

using namespace std;

void permute(string prefix, string str){
	if (str.length() == 0)
	{
		cout << prefix <<endl;
		return;
	}

	for (auto i = 0; i < str.length(); i++)
		permute(prefix + str[i], str.substr(0, i) + str.substr(i + 1));
}

int main()
{
	string s = "abc";
	permute("", s);
	return 0;
}
