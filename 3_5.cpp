#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void ReverseWord(string &str, int start, int end)
{
	while(start < end)
	{
		swap(str[start++], str[end--]);
	}
}

string ReverseSentence(string str)
{
	int L = str.size();
	if(L <= 1)
		return str;

	// 翻转整个字符串
	ReverseWord(str, 0, L - 1);
	
	// 翻转每个单词
	int w_start = 0;
	int w_end = 0;
	int i = 0;
	while(i < L)
	{
		// 跳过空格部分
		while(str[i] == ' ')
			i++;
		w_start = i;
		w_end = i;
		i++;

		while(i < L && str[i] != ' ')
		{
			w_end++;
			i++;
		}
		ReverseWord(str, w_start, w_end);	
	}		

	return str;
}

int main()
{
	string str = "abc 12345 6789 876 54   4321325366787    2739187397  271937237   39";
	cout << "str: " << str << endl;

	string convert_str = ReverseSentence(str);
	cout << "convert str: " << convert_str << endl;
	return 0;
}
