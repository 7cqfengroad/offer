#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers)
{
	int L = numbers.size();
	if(L != 5)
		return false;
	
	// 先对扑克升序排序
	sort(numbers.begin(), numbers.end(), less<int>());	
	//统计0
	int count_zeros = 0;
	int count_diff = 0;
	int index = 0;
	for(int i = 0; i < L; i++)
	{
		if(numbers[i] == 0)
		{
			count_zeros++;
			continue;
		}
		index = i;
		break;
	}	
	if(count_zeros == 4)
		return true;
	for(int i = index; i < L - 1; i++)
	{
		if(numbers[i+1] - numbers[i] == 0)
			return false;
		count_diff += numbers[i+1] - numbers[i] - 1;
	}	

	if(count_diff <= count_zeros)
		return true;

	return false;
}


int main()
{
	int a[5] = {1, 0, 0, 1, 0};
	vector<int> vec(a, a+5);
	bool flag = IsContinuous(vec);
	cout << "flag: " << flag << endl;

	return 0;
}
