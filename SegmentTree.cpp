#include <string>
#include <vector>
#include <array>


using namespace std;

class SegmentTree
{
private:
	std::array<int, 256> _tree;
public:
	SegmentTree(vector<int> &arr)
	{
		constructSTUtil(arr, 0, arr.size() - 1, 0);
	}
	int getMax(int left, int right)
	{

	}
	int getMid(int s, int e) { return s + (e - s) / 2; }

	int constructSTUtil(vector<int> arr, int segmentStart, int segmentEnd, int si)
	{
		if (segmentStart == segmentEnd)
		{
			_tree[si] = arr[segmentStart];
			return arr[segmentStart];
		}

		int mid = getMid(segmentStart, segmentEnd);
		_tree[si] = constructSTUtil(arr, segmentStart, mid,  si * 2 + 1) +
			constructSTUtil(arr, mid + 1, segmentEnd,  si * 2 + 2);
		return _tree[si];
	}
};

int main()
{
	vector<int> arr{ 1, 3, 5, 7, 9, 11 };
	SegmentTree st(arr);
	return 0;
}
