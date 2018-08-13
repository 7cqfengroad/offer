#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> pstr;

void SonPer(string str, char *begin)
{
	if(*begin == '\0')
	{
		pstr.push_back(str);
	}
	else
	{
		for(char *ch = begin; (*ch) != '\0'; ch++)
		{
			cout << "*ch: " << *ch << endl;
			cout << "behind begin: " << *begin << endl;
			char tmp = *ch;
			*ch = *begin;
			*begin = tmp;
			cout << "str: " << str << endl;
			cout << "after begin: " << *begin << endl;
			SonPer(str, begin + 1);
			tmp = *ch;
			*ch = *begin;
			*begin = tmp;
			
		}			
	}
}

vector<string> Permutation(string str)
{
	SonPer(str, &str[0]);

	return pstr;		
}


int main()
{
	string str = "one";
	char astr[] = "one";

	vector<string> rstr = Permutation(astr);
	for(int i = 0; i < rstr.size(); i++)
	{
		cout << rstr[i] << endl;
	}

	return 0;
}
