#include <iostream>
#include <vector>
#include <string>

using namespace std;

int FirstNotRepeatingChar(string str)
{
	if(str.size() == 0)
	{
		return -1;
	}
	int counts[52] = {0}; // 一定要手动初始化为0
	int locates[52] = {0};

	// 统计字母出现的次数和第一次出现的位置 考虑大小写字母
	for(int n_i = 0; n_i < str.size(); n_i++)
	{
		int id;
		if(int(str[n_i]) >= 65 && int(str[n_i]) <= 90)  // A~Z 的ASCII: 65~90
		{
			id = int(str[n_i]) - 65;
		}
		else if(int(str[n_i]) >= 97 && int(str[n_i]) <= 122)  // a~z 的ASCII: 97~122
		{
			id = int(str[n_i]) - 97 + 26;
		}
		counts[id]++;
		if(locates[id] == 0)
		{
			locates[id] = n_i + 1;
		}
	}		
	
	// 判断第一个只出现一次的字符	
	vector<int> one_locate;
	for(int i = 0; i < 52; i++)
	{
		if(counts[i] == 1)
		{
			one_locate.push_back(locates[i]);	
		}
	}	
	if(one_locate.empty())
	{
		return -1;
	}
	int min = one_locate[0];
	for(int i = 0; i < one_locate.size(); i++)
	{
		if(min > one_locate[i])
		{
			min = one_locate[i];
		}
	}

	return min;
}

int main()
{
	string str = "babababababc";

	//cout << "a: " << int(str[0]) << endl;
	//cout << "A: " << int(str[1]) << endl;
	int locate = FirstNotRepeatingChar(str);
	cout << "str: " << str << "  one_locate: " << locate << endl; 
	return 0;
}
