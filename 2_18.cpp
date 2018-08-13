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

	int max_dep = max(left + 1, right + 1);

	return max_dep; 
}

bool IsBalanced_Solution(PNode pRoot)
{
	bool state;
	if(pRoot == NULL)
	{
		state = true;
	}
	else
	{
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		if((left - right <= 1) || (right - left <= 1) )
		{
			state = true;
		}
		else
		{
			state = false;
		}
	}
	bool left_state = true;
	if(pRoot->left != NULL)
	{
		left_state = IsBalanced_Solution(pRoot->left);	
	}
	
	bool right_state = true;
	if(pRoot->right != NULL)
	{
		right_state = IsBalanced_Solution(pRoot->right);	
	}
	
	return state & left_state & right_state;
}

int main()
{
	PNode T;
	cout << "create tree" << endl;
	CreateTree(T);
	cout << "create ok" << endl;
	
	bool state = IsBalanced_Solution(T);
	cout << "state: " << state << endl;

	return 0;
}
