#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> pstr;

void SonPer(string str, int begin)
{
	if(begin == str.size())
	{
		pstr.push_back(str);
	}
	else
	{
		for(int ch = begin; ch < str.size(); ch++)
		{
			char tmp = str[ch];
			str[ch] = str[begin];
			str[begin] = tmp;
			//cout << "str: " << str << endl;
			SonPer(str, begin + 1);
			tmp = str[ch];
			str[ch] = str[begin];
			str[begin] = tmp;
			
		}			
	}
}

vector<string> Permutation(string str)
{
	if(str.size() == 0)
	{
		return pstr;
	}
	SonPer(str, 0);

	return pstr;		
}

int main()
{
	char astr[] = "one";

	vector<string> rstr = Permutation(astr);
	for(int i = 0; i < rstr.size(); i++)
	{
		cout << rstr[i] << endl;
	}

	return 0;
}
