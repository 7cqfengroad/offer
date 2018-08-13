#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "abc cds";
	str = str.substr(0, 3);
	cout << "str: " << str << endl;
	return 0;	
} 
