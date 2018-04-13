#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print_subsets(vector<string> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

void subsets(string str) {
	vector<string> subsets;
	subsets.push_back("");
	for (int i = 0; i < str.size(); i++) {
		int size = subsets.size();
		for (int j = 0; j < size; j++) {
			subsets.push_back(subsets[j] + str[i]);
		}
	}
	print_subsets(subsets);
}

int main() {
	string str;
	cin >> str;
	subsets(str);
	while (1);
	return 0;
}