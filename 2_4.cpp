#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}Tree, *PTree;

void CreatTree(PTree &T)
{
	int val;
	cin >> val;
	if(val == -1)
	{
		return;
	}
	else
	{
		T = new Tree;
		T->val = val;
		CreatTree(T->left);
		CreatTree(T->right);
	}
}

vector<vector<int> > buffer;
vector<int> tmp;	
vector<vector<int> > FindPath(PTree root, int num)
{
	if(root == NULL)
	{
		return buffer;
	}
	tmp.push_back(root->val);
	cout << "root->val: " << root->val << endl;
	if(num - root->val == 0 && root->left == NULL & root->right == NULL)
	{
		buffer.push_back(tmp);	
		cout << "route: ";
		for(int l_i = 0; l_i < tmp.size(); l_i++)
		{
			cout << tmp[l_i] << " ";
		}
		cout << endl;
	}
	FindPath(root->left, num - root->val);	
	FindPath(root->right, num - root->val);	
	if(tmp.size() != 0)
	{
		tmp.pop_back();
	}

	return buffer;
}

int main()
{
	PTree T;
	cout << "please create a tree: " << endl;
	CreatTree(T);
	cout << "ok" << endl;

	vector<vector<int> > a;
	cout << "find path" << endl;
	a = FindPath(T, 8);
	cout << "find ok" << endl;
	
	return 0;	
}
