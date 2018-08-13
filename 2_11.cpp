#include <iostream>
#include <vector>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}

	vector<int> front;
	vector<int> mid;
	vector<int> behind;

	int iter = 1;
	int f = n;
	int count = 0;

	while(f > 0)
	{
		f = n / (iter * 10);
		int m = (n - f * iter * 10) / iter;
		int b = n % iter; 	
		front.push_back(f);
		mid.push_back(m);
		behind.push_back(b);
		count++;
		iter = iter * 10;
	}   		

	for(int i = 0; i < count; i++)
	{
		cout << "mid: " << mid[i] << " front: " << front[i] << "  behind: " << behind[i] << endl;
	}
	
	int sum = 0;
	iter = 1;
	for(int i = 0; i < count; i++)
	{
		sum += front[i] * iter;
		if(mid[i] > 1)
		{
			sum += iter;	
		}
		else if(mid[i] == 1)
		{
			sum += behind[i];
			if(iter > 1)
			{
				sum += 1;   // 算上0
			}
		}
		iter = iter * 10;
	}

	return sum;	
}

int main()
{
	int n = 11;
	int sum;
	sum = NumberOf1Between1AndN_Solution(n);
	cout << "n = " << n << "  sum = " << sum << endl;
}
