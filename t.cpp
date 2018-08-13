#include <iostream>

using namespace std;

void change(int a, int &b, int* &c)
{
	cout << "come in" << endl;
	a = 2;
	cout << "come in" << endl;
	b = 3;
	cout << "come in" << endl;
	c = new int;
	*c = 5;
	cout << "come in" << endl;

	cout << "In function: " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << *c << endl;
}

int main()
{
	int a = 1, b = 2;
	int *c;
	cout << "c: " << *c << endl;
	change(a, b, c);
	
	cout << "In main: " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << *c << endl;

	return 0;
}
