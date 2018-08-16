#include <iostream>
#include <vector>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
	if(length <= 1)
		return false;
	vector<int> count;	
	for(int i = 0; i < length; i++)
	{
		count.push_back(0);
	}
	for(int i = 0; i < length; i++)
	{
		count[numbers[i]] += 1;
		if(count[numbers[i]] == 2)
		{
			*duplication = numbers[i];
			return true;
		}
	}		

	return false;
}

int main()
{
	int a[10] = {1, 0, 2, 3, 5, 4, 6, 8, 7, 9};
	int dup = 0;
	bool flag = duplicate(a, 10, &dup);
	cout << "flag: " << flag << " dup: " << dup << endl;
	return 0;
}
