#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	int len_max = array[0];

	for(int len = 1; len <= array.size(); len++)
	{
		for(int i = 0; i <= array.size() - len; i++)
		{
			int len_sum = array[i];
			for(int j = i + 1; j < i + len; j++)
			{
				len_sum += array[j];
			}	
			cout << "len: " << len << " i = " << i << "  len_sum: " << len_sum << endl;
			if(len_max < len_sum)
			{
				len_max = len_sum;
			}
		}
	}		

	return len_max;
}

void show(vector<int> vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	//int a[10] = {-1, 2, 5, -3, 9, 0, 6, -7, 10, -8};
	//int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};
	int a[5] = {2, 8, 1, 5, 9};
	vector<int> vec(a, a+5);
	show(vec);
	
	int max = FindGreatestSumOfSubArray(vec);
	cout << "max: " << max << endl;
	return 0;	
}
