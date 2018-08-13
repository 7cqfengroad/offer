#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
}Node, *PNode;

void CreateTree(PNode &T)
{
	int c;
	cin >> c;
	if(c == -1)
	{
		T = NULL;		
	}
	else
	{
		T = new Node;
		T->val = c;
		CreateTree(T->left);
		CreateTree(T->right);
	}
}

int TreeDepth(PNode &T)
{
	if(T == NULL)
		return 0;
	int left = TreeDepth(T->left);
	int right = TreeDepth(T->right);
	cout << "left: " << left << endl;
	cout << "right: " << right << endl;

	int max_dep = max(left + 1, right + 1);
	cout << "max dep: " << max_dep << endl;

	return max_dep; 
}

int main()
{

	PNode T = new Node;
	T->val = 1;
	T->left = new Node;
	T->right = new Node;
	PNode lleft = T->left;
	lleft->left = NULL;
	lleft->right = NULL;
	lleft->val = 2;
	PNode lright = T->right;
	lright->left = NULL;
	lright->right = NULL;
	lright->val = 3;

	cout << "left: " << T->left->val << endl;
	cout << "right: " << T->right->val << endl;
	PNode tmp = lleft;
	T->left = T->right;
	T->right = lleft;
	cout << "left: " << T->left->val << endl;
	cout << "right: " << T->right->val << endl;
/*
	cout << "Crate Tree" << endl;
	PNode T;
	CreateTree(T);
	cout << "ok" << endl;

	int dep = TreeDepth(T);
	cout << "dep: " << dep << endl;
	return 0;
*/
}
