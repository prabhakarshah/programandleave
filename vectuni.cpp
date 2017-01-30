#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;
using std::unique_ptr;

int main()
{
	vector<unique_ptr<string>> v;
	unique_ptr<string> up(new string("alpha"));
	v.push_back(std::move(up));
	return v.size();
}
