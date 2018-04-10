#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


struct trieNode {
	trieNode* children[26];
	int count[26];
	trieNode() : count{ 0 }, children(){};
};

void trie_add(trieNode* root, string contact) {
	trieNode* temp = root;
	int index;
	for (int i = 0; i < contact.size(); i++) {
		index = contact[i] - 'a';
		if (!(temp->children[index])) {
			temp->children[index] = new trieNode();
		}
		temp = temp->children[index];
		temp->count[index]++;
	}
}

int trie_search(trieNode* root, string contact) {
	trieNode* temp = root;
	int index, i;
	for (i = 0; i < contact.size() && temp; i++) {
		index = contact[i] - 'a';
		if (!(temp->children[index])) {
			break;
		}
		temp = temp->children[index];
	}
	if (i == contact.size())
		return temp->count[index];
	return 0;
}


int main() {
	int n;
	cin >> n;
	trieNode* root = new trieNode();
	for (int a0 = 0; a0 < n; a0++) {
		string op;
		string contact;
		cin >> op >> contact;
		if (op == "add") {
			trie_add(root, contact);
		}
		else {
			cout << trie_search(root, contact) << endl;
		}
	}
	return 0;
}
