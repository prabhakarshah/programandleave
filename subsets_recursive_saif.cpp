#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsets(string str, string sub, int i, int n) {
	if (i == n) {
		cout << sub << endl;
		return;
	}
	subsets(str, sub + str[i], i + 1, n);
	subsets(str, sub, i + 1, n);

}

int main() {
	string str;
	string sub = "";
	cin >> str;
	subsets(str, sub, 0, str.size());
	while (1);
	return 0;
}