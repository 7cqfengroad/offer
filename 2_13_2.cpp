#include <iostream>
#include <vector>

using namespace std;

int Min(int number1, int number2, int number3)
{
	int min = (number1 > number2) ? number2 : number1;
	
	return ((min > number3) ? number3 : min);
}

int GetUglyNumber_Solution(int index)
{
	if(index <= 0)
	{
		return 0;
	}
	
	int *ugly = new int[index];
	ugly[0] = 1;
	int *ugly2 = ugly;
	int *ugly3 = ugly;
	int *ugly5 = ugly;
	int nextugly = 1;

	while(nextugly < index)
	{
		int min = Min(*ugly2 * 2, *ugly3 * 3, *ugly5 * 5);
		ugly[nextugly] = min;
		
		while(*ugly2 * 2 <= ugly[nextugly])
		{
			++ugly2;
		}	
		while(*ugly3 * 3 <= ugly[nextugly])
		{
			++ugly3;
		}	
		while(*ugly5 *5 <= ugly[nextugly])
		{
			++ugly5;
		}	

		nextugly++;

	}
	int ugly_index = ugly[nextugly - 1];	
	delete[] ugly;
	
	return ugly_index;
}

int main()
{
	int index = 10;
	int ugly_index = GetUglyNumber_Solution(index);

	cout << "index: " << index << "   ugly_index: " << ugly_index << endl;
	return 0;
}
