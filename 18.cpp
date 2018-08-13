#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int a1[5] = {1, 2, 3, 4, 5};
//	int a1[2] = {1, 2};
//	int a2[2] = {3, 4};
	vector<vector<int> > b;
	vector<int> b1(a1, a1+5);
//	vector<int> b2(a2, a2+2);
	b.push_back(b1);
//	b.push_back(b2);

	for(int i = 0; i < 1; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << b[i][j] << ' ';	
		}
		cout << endl;
	}

	int height = b.size();
	int weight = b[0].size();
	int begin_i = 0, begin_j = 0;
	int end_i = height - 1, end_j = weight - 1;
        cout << "height: " << height << endl;
	cout << "weight: " << weight << endl;
	cout << "end_i: " << end_i << endl;
	cout << "begin_i: " << begin_i << endl;
	
	if(height == 0 || weight == 0)
		return 0;
	vector<int> c;
	
	while((end_i >= begin_i) && (end_j >= begin_j))
	{
		for(int i = begin_i, j = begin_j; j <= end_j; j++)
		{
			cout << b[i][j] << ' ';
			c.push_back(b[i][j]);
		}	
		for(int i = begin_i + 1, j = end_j; i < end_i; i++)
		{
			cout << b[i][j] << ' ';
			c.push_back(b[i][j]);
		}	
		for(int i = end_i, j = end_j; (j >= begin_j) && (i > begin_i); j--)
		{
			cout << b[i][j] << ' ';
			c.push_back(b[i][j]);
		}
		for(int i = end_i - 1, j = begin_j; i > begin_i; i--)
		{
			cout << b[i][j] << ' ';
			c.push_back(b[i][j]);
		}
		end_i = end_i - 1;
		end_j = end_j - 1;
		begin_i = begin_i + 1;
		begin_j = begin_j + 1;
	}	
	cout << endl << "ok" << endl;
	for(int i = 0; i < c.size(); i++)
	{
		cout << c[i] << ' ';
	}
	cout << endl;

	return 0;
}
