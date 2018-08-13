#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	if(input.size() <= k)
	{
		return input;
	}

	vector<int> small_k;
	if(k <= 0)
	{
		return small_k;
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = input.size() - 1; j > 0; j--)
		{
			if(input[j] < input[j - 1])
			{
				int tmp = input[j];
				input[j] = input[j - 1];
				input[j - 1] = tmp;
			}
		}
		small_k.push_back(input[i]);
	}	

	return small_k;
}

int main()
{
	int a[8] = {2, 2, 3, 7, 8, 1, 4, 6};
	vector<int> vec(a, a+8);
	show(vec);			

	vector<int> small_k = GetLeastNumbers_Solution(vec, 9);
	show(small_k);			
}
