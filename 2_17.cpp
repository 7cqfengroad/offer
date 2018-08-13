#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> data, int k, int begin, int end)
{
	while(begin <= end)
	{
		int mid = (begin + end) / 2;
		if(data[mid] == k)
		{
			return mid;
		}
		else if(k < data[mid])
		{
			end = mid - 1;
		}
		else if(k > data[mid])
		{
			begin = mid + 1;
		}
	}	
	
	return -1;	
}

int GetNumberOfK(vector<int> data, int k)
{
	if(data.size() == 0)
	{
		return 0;
	}
	int locate = find(data, k, 0, data.size());
	if(locate == -1)
	{
		return 0;
	}
	int count = 1;
	for(int i = locate - 1; i >= 0; i--)
	{
		if(data[i] != k)
		{
			break;
		}
		count++;
	}
	for(int i = locate + 1; i < data.size(); i++)
	{
		if(data[i] != k)
		{
			break;
		}
		count++;
	}
	return count;	
}

int main()
{
	int a[8] = {1, 1, 1, 4, 5, 5, 5, 5};	
	vector<int> vec(a, a+8);
	int k = 5;

	int count = GetNumberOfK(vec, k);
	cout << "k = " << k << "  count: " << count << endl;

	return 0;
}
