#include <iostream>
#include <vector>

using namespace std;

//  一下这种方法超时
int GetUglyNumber_Solution(int index)
{
	if(index <= 0)
	{
		return 0;
	}	
	if(index == 1)
	{
		return 1;
	}
	
	int count = 1;
	int iter_num = 2, num = 2;   // 判断目标  
	
	while(count < index)
	{
		if((num / 2 > 1) && (num % 2 == 0))
		{
			num = num / 2;
			continue;
		}		
		else if((num / 3 > 1) && (num % 3 == 0))
		{
			num = num / 3;
			continue;
		}		
		else if((num / 5 > 1) && (num % 5 == 0))
		{
			num = num / 5;
			continue;
		}		
		else if(((num / 2 == 1) && (num % 2 == 0)) || ((num / 3 == 1) && (num % 3 == 0)) || ((num / 5 == 1) && (num % 5 == 0)))
		{
			if((++count) == index)
			{
				break;
			}
			else
			{
				iter_num++;
				num = iter_num;
				continue;	
			}
		}
		else
		{
			iter_num++;
			num = iter_num;
		}
	}

	return iter_num;	
}

int main()
{
	int index = 10;	
	int num = GetUglyNumber_Solution(index);	
	
	return 0;
}
