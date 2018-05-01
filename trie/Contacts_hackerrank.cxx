
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Trie
{
public:
	struct trienode
	{
		bool oft{ false };
		trienode *child[26];
		trienode(){
			for (int i = 0; i < 26; i++) child[i] = nullptr;
		}
	};

	void insert(string word)
	{
		if (root == nullptr)
			root = new trienode;

		auto cur = root;
		size_t size = word.length();
		for (int i = 0; i< size; ++i)
		{
			int c = word[i] - 'a';
			if (cur->child[c] == nullptr)
			{
				cur->child[c] = new trienode;
			}
			cur = cur->child[c];
		}
		cur->oft = true;
	}



	int countnumbers(string prefix)
	{
		trienode * curr = root;
		for (auto i = 0; i< prefix.length(); ++i)
		{
			int c = prefix[i] - 'a';
			if (curr->child[c] == nullptr)
				return 0;
			curr = curr->child[c];
		}
		if (curr == nullptr)
			return 0;
		int count = 0;
		counthelper(curr, count);
		return count;
	}
private:
	trienode *root = nullptr;

private:

	void counthelper(trienode *node, int& count)
	{
		if (node == nullptr)
			return;

		if (node->oft == true)
			count++;

		for (int i = 0; i<26; i++)
			counthelper(node->child[i], count);
	}

};
vector<int> contacts(vector<vector<string>> queries) {
	vector<int> out;

	int size = queries.size();
	Trie trie;

	for (auto i = 0; i < size; i++)
	{
		if (queries[i][0] == "add")
		{
			trie.insert(queries[i][1]);
		}
		else if (queries[i][0] == "find")
		{
			out.push_back(trie.countnumbers(queries[i][1]));
		}
	}

	return out;

}

int main()
{
	ostream& fout = cout;

	int queries_rows;
	cin >> queries_rows;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<string>> queries(queries_rows);
	for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
		queries[queries_row_itr].resize(2);

		for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
			cin >> queries[queries_row_itr][queries_column_itr];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	vector<int> result = contacts(queries);

	for (int result_itr = 0; result_itr < result.size(); result_itr++) {
		fout << result[result_itr];

		if (result_itr != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";


	return 0;
}
