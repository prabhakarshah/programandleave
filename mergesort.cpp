#include <iostream>
#include <queue>
#include <exception>

using namespace std;


class Sol
{
	int arr[10];
	int size ;
	public:

		void merge_sort(int low, int high)
		{
			if(low < high)
			{
				auto mid = (low + high) /2;
				merge_sort(low,mid);
				merge_sort(mid+1, high);
				merge(low, mid, high);
			}
		}

		void merge(int low, int mid, int high)
		{

			queue<int> fhalf, shalf;
			for(int i= low ; i <= mid ; ++i)
				fhalf.push(arr[i]);
			for(int i= mid+1 ; i <= high; ++i)
				shalf.push(arr[i]);

			int i=low;
			while( !fhalf.empty()  && !shalf.empty())
			{
				if( fhalf.front() < shalf.front())
				{
					arr[i++] = fhalf.front();
					fhalf.pop();
				}
				else
				{
					arr[i++] = shalf.front();
					shalf.pop();
				}
			}

			while (!fhalf.empty()) {
				arr[i++] = fhalf.front();
				fhalf.pop();
			}

			
			while (!shalf.empty()) {
				arr[i++] = shalf.front();
				shalf.pop();
			}

		}

		void Main()
		{
			std::cin>>size;
			if(size > 9 )
				throw std::exception();
			for(int i=0; i< size ;i++)
				std::cin>>arr[i];

			///call merge_sort
			merge_sort(0,size-1);

			for(auto a = 0; a < size ; a++ )
				std::cout<< arr[a] << " ";

			std::cout<< std::endl;
		}
};

int main()
{
	Sol sol;
	sol.Main();
	return 0;
}
