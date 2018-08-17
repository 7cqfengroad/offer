#include <iostream>
#include <string>

using namespace std;

bool isNumeric(char* string)
{
	if(string == NULL)
		return false;
	if(*string == '+' || *string == '-')
		string++;
	if(*string == '\0')
		return false;
	int dot = 0, num = 0, nume = 0;
	while(*string != '\0')	
	{
		if(*string >= '0' && *string <= '9')
		{
			string++;
			num++;
		}
		else if(*string == '.')
		{
			if(dot > 0 || nume > 0)
				return false;
			string++;
			dot++;
		}
		else if(*string == 'e' || *string == 'E')
		{
			if(num == 0 || nume > 0)
				return false;
			string++;
			nume++;
			if(*string == '-' || *string == '+')
				string++;
			if(*string == '\0')
				return false;
		}
		else
			return false;
	}

	return true;
}

int main()
{
	char str[] = "12e";
	bool flag = isNumeric(str);
	cout << "flag: " << flag << endl;

	return 0;
}
