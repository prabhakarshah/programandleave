#include <iostream>
#include <vector>
#include <array>


using namespace std;

class SegmentTree
{
private:
	std::array<int, 256> _tree;
	int _size = 0;
public:
	SegmentTree(vector<int> &arr)
	{
		constructSTUtil(arr, 0, arr.size() - 1, 0);
		_size = arr.size();
	}
	
	int getSum(int queryStart, int queryEnd)
	{
		return getSum(0, _size-1, queryStart, queryEnd);
	}

private:

	int getSum(int segmentStart, int segmentEnd, int queryStart, int queryEnd, int si=0)
	{
		// If segmentEndgment of this node is a part of given range, then return
		// the sum of the segmentEndgment
		if (queryStart <= segmentStart && queryEnd >= segmentEnd)
			return _tree[si];

		// If segmentEndgment of this node is outside the given range
		if (segmentEnd < queryStart || segmentStart > queryEnd)
			return 0;

		// If a part of this segmentEndgment overlaps with the given range
		int mid = getMid(segmentStart, segmentEnd);

		return getSum(segmentStart, mid, queryStart, queryEnd, 2 * si + 1) +
			getSum(mid + 1, segmentEnd, queryStart, queryEnd, 2 * si + 2);
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
	std::cout << st.getSum(1, 3);
	return 0;
}
