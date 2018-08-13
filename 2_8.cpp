#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if(numbers.size() == 0)
	{
		return 0;
	}
	sort(numbers.begin(), numbers.end());
	int mid = numbers.size() / 2;
	for(int i = 0; i < numbers.size() - mid; i++)
	{
		if(numbers[i + mid] == numbers[i])
		{
			return numbers[i];
		}	
	} 	

	return 0;
}

int main()
{
	int a[5] = {2, 2};
	vector<int> vec(a, a+2);
	for(int vi = 0; vi < vec.size(); vi++)
	{
		cout << vec[vi] << " ";
	}
	cout << endl;
	
	//sort(vec.begin(), vec.end());
	int flag = MoreThanHalfNum_Solution(vec);
	cout << "flag: " << flag << endl;

	return 0;
}
