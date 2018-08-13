#include <iostream>
#include <vector>

using namespace std;

bool IsPopOrder(vector<int> a, vector<int> b)
{
	vector<int>:: iterator it1;
	vector<int>:: iterator it2;
	for(it1 = a.begin(), it2 = b.end() - 1; it1 != a.end(); it1++, it2--)
	{
		cout << "it1: " << *it1 << "  it2: " << *it2 << endl;
		if(*it1 != *it2)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {5, 4, 3, 2, 1};
	vector<int> aa(a, a+5);
	vector<int> bb(b, b+5);

	bool r = IsPopOrder(aa, bb);
	cout << "result: " << r << endl;
	cout << "ok" << endl;
	return 0;
}
