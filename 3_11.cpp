#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &A)
{
	vector<int> B(A);
	int L = A.size();
	if(L == 0)
		return B;
	vector<int> C(A);
	vector<int> D(A);

	C[0] = 1;
	for(int i = 1; i < L; i++)
	{
		C[i] = C[i-1] * A[i-1];
	}
	D[L-1] = 1;
	for(int i = L-2; i >= 0; i--)
	{
		D[i] = D[i+1] * A[i+1];	
		B[i] = C[i] * D[i];
	}
	B[L-1] = D[L-1] * C[L-1];

	return B;
}

void show_vec(vector<int> vec)
{
	int L = vec.size();
	for(int i = 0; i < L; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> A(a, a+8);
	vector<int> B = multiply(A);
	show_vec(A);	
	show_vec(B);

	return 0;	
}
