#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) 
{
    vector<int> nums;
    int L = array.size();
    if(L < 2)
    {
        return nums;
    }
    int begin = 0;
    int end = L - 1;
    int cursum = 0;
    int mul = 0;
    
    while(begin <= end)
    {
        cursum = array[begin] + array[end];
        if(cursum == sum)
        {
            cout << "array[begin]: " << array[begin] << "  array[end]: " << array[end] << endl; 
            int curmul = array[begin] * array[end];
            if(mul == 0 && nums.empty() == 1)
            {
                mul = curmul;
                nums.push_back(array[begin]);
                nums.push_back(array[end]);
            }
            else
            {
                if(mul > curmul)
                {
                    mul = curmul;
                    nums[0] = array[begin];
                    nums[1] = array[end];
                }
            }
            begin++;
        }
        if(cursum < sum)
            begin++;
        if(cursum > sum)
            end--;
    }
    
    return nums;
}

int main()
{
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> vec(a, a+8);

	vector<int> nums = FindNumbersWithSum(vec, 100);
	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}
