#include <iostream>
#include <vector>

using namespace std;

vector<int> AddContinuousToVec(int small, int big)
{
	vector<int> sub;
	for(int i = small; i <= big; i++)
	{
		sub.push_back(i);
	}	

	return sub;
}

void show_vec(vector<int> vec)
{
	int L = vec.size();
	for(int i = 0; i < L; i++)
	{
		cout << vec[i] << " ";
	}	 
	cout << endl;
}

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > sequence;
	if(sum < 3)
		return sequence;
	int small = 1;
	int big = 2;
	int Cursum = small + big;
	int mid = (1 + sum) / 2;
	
	while(small < mid)
	{
		if(Cursum == sum)
		{
			vector<int> sub = AddContinuousToVec(small, big);			
			sequence.push_back(sub);
			show_vec(sub);
		}			
		while(Cursum > sum && small < mid)
		{
			Cursum -= small;
			small++;	
			if(Cursum == sum)
			{
				vector<int> sub = AddContinuousToVec(small, big);			
				sequence.push_back(sub);
				show_vec(sub);
			}			
		}

		big++;
		Cursum += big;
	}		

	return sequence;
}

int main()
{
	vector<vector<int> > sequence;
	sequence = FindContinuousSequence(20);	

	return 0;
}
