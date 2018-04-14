#include<iostream>
#include<vector>
#include<string>
using namespace std;

string max(string a, string b) {
	return a.size() > b.size() ? a : b;
}

string subse(string str1, string str2, int i, int j) {
	if (i == str1.size() || j == str2.size())
		return "";
	if (str1[i] == str2[j])
		return str1[i] + subse(str1, str2, i + 1, j + 1);
	return max(subse(str1, str2, i + 1, j), subse(str1, str2, i, j + 1));

}

int main() {
	string str1 = "aggtab";
	string str2 = "gxtxayb";
	//	cin >> str1>>str2;
	cout << subse(str1, str2, 0, 0);
	while (1);
	return 0;
}