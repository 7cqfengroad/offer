#include <iostream>
#include <vector>

using namespace std;

int InversePairs(vector<int> data)
{
	int count = 0;
	for(int i = 0; i < data.size() - 1; i++)
	{
		for(int j = 0; j < data.size() - 1 - i; j++)
		{
			if(data[j] > data[j + 1])
			{
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
				count++;
			}
		}
	}

	return count % 1000000007;
}

int main()
{
	int a[] = {8, 2, 3, 4, 5, 6, 7, 0, 1};
	vector<int> b(a, a+9);

	int count = InversePairs(b);
	cout << "count: " << count << endl;

	return 0;
}
