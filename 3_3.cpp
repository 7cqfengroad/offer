#include <iostream>
#include <string>

using namespace std;

string LeftRotateString(string str, int n)
{
	int L = str.size();
	if(n == 0 || L == 0)
		return str;
	string convert_str;
	n = n % L;
	for(int i = 0; i < n; i++)
	{
		convert_str.push_back(str[i]);
	}
	for(int i = 0; i < L - n; i++)
	{
		str[i] = str[i + n];
	}
	for(int i = 0; i < n; i++)
	{
		str[L-n+i] = convert_str[i];
	}

	return str;
}

int main()
{
	string str = "abcXYZdef";
	cout << "str: " << str << endl;
	string convert_str = LeftRotateString(str, 15);
	cout << "convert_str: " << convert_str << endl;
	return 0;
}
