#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int StrToInt(string str)
{
	int L = str.size();
	if(L == 0)
		return 0;

	int num = 0;
	int sign_index = -1;
	for(int i = L-1; i >= 0; i--)
	{
		if(str[i] == 43 || str[i] == 45)
		{
			if(i != 0 || sign_index != -1)
				return 0;
			sign_index = L-i-1;
			continue;
		}
		if(str[i] <= 57 && str[i] >= 48)
		{
			num += (str[i] - '0') * pow(10, L-i-1); 
			continue;
		}
		return 0;
	}

	if(sign_index != -1)
	{
		if(str[0] == 45)  // 为负号
			return num * (-1);
		return num;	
	}

	return num;
}


int main()
{
	string str = "-12+35";
	int num = StrToInt(str);
	cout << "num: " << num << endl;

	return 0;
}
