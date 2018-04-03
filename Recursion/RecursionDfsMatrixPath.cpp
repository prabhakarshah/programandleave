/*Problem statement
* Find region with max 1s in a given matrix
* author: pixelr
* License : BSD-2 Clause
*/
#include <iostream>
#include <vector>
#include <array>

using namespace std;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;

bool isInside(int i, int j,int m,int n){
	return i >= 0 && j >= 0 && i < m && j < n;
}

void find_max_region_length(const vvi &matrix, vvb &visited, int localmax, int &maximum,int i, int j)
{
	if (!isInside(i, j, matrix.size(), matrix[0].size()))
		return;


	visited[i][j] = true;
	maximum = std::max(localmax, maximum);


	for (auto r = -1; r < 2; r++)
	for (auto c = -1; c < 2; c++)
	{
		if (isInside(i+r, j+c, matrix.size(), matrix[0].size()) 
			&& matrix[i + r][j + c]>0
			&& visited[i + r][j + c] != false 
			)
		{
			std::cout << "At [" << i << ", " << j << "]\n";
			find_max_region_length(matrix,visited,localmax+1,maximum,i+r,j+c);
		}
	}

}

int main()
{
	vvi matrix{ {1,1,0,0,0}, 
				{0,1,1,0,0},
				{0,0,1,0,1},
				{1,0,0,0,1},
				{0,1,0,1,1}
	};

	vvb visited(5, vector<bool>(5, false));

	int maximum{ 0 };
	for (int i = 0; i < matrix.size(); ++i)
	for (int j = 0; j < matrix.size(); ++j)
	{
		if (matrix[i][j]>0)
		find_max_region_length(matrix,visited,0,maximum,i,j);
	}
	
	cout << "Max region Lenght:" << maximum;
	return 0;
}
