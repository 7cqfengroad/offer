#include <iostream>
#include <vector>

using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
{
	if(data.size() < 2)
	{
		return;
	}
	int OR = 0;
	for(int i = 0; i < data.size(); i++)
	{
		OR ^= data[i];
	}	
	cout << "OR" << OR << endl;

	int index = 0;
	while(((OR & 1) == 0) && (index < 8 * sizeof(int)))
	{
		OR = OR >> 1;
		index++;
	}
	cout << "index: " << index << endl;

	vector<int> same;
	vector<int> no_same;
	for(int i = 0; i < data.size(); i++)
	{
		int ob = data[i] >> index;
		if(ob & 1 != 0)
		{
			same.push_back(data[i]);
		}
		else
		{
			no_same.push_back(data[i]);
		}
		
	}	

	int one = 0;
	int two = 0;
	cout << "same" << endl;
	for(int i = 0; i < same.size(); i++)
	{
		cout << same[i] << " ";
		one ^= same[i];
	}
	cout << endl << "no same" << endl;
	for(int i = 0; i < no_same.size(); i++)
	{
		cout << no_same[i] << " ";
		two ^= no_same[i];
	}
	cout << endl;

	*num1 = one;
	*num2 = two;
}

int main()
{
	int a[] = {2, 4, 3, 6, 3, 6, 5, 5};
	vector<int> data(a, a+8);
	int num1, num2;

	FindNumsAppearOnce(data, &num1, &num2);
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	return 0;
	
}
