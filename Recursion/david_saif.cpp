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

int arr[37];

int climb_up(int n){
	if (arr[n])
		return arr[n];
	if (n <= 0){
		if (!n)
			return 1;
		return 0;
	}
	for (int i = 1; i <= 3; i++){
		arr[n] += climb_up(n - i);
	}
	return arr[n];
}

int main(){
	int s;
	cin >> s;
	for (int a0 = 0; a0 < s; a0++){
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++)
			arr[i] = 0;
		cout << climb_up(n) << endl;
	}
	return 0;
}
