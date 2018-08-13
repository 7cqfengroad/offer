#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode()
	{
		this->left = NULL;
		this->right = NULL;
	}
};

void CreateTree(struct TreeNode* &T)
{
	int a;
	cin >> a;
	if(a == -1)
	{
		T = NULL;
	}
	else
	{
		T = new struct TreeNode;
		T->val = a;
		CreateTree(T->left);
		CreateTree(T->right);
	}
}

void ConvertNode(TreeNode *PNode, TreeNode **PLastNode)
{
	if(PNode == NULL)
	{
		return;
	}
	TreeNode *PCurrentNode = PNode;
	if(PCurrentNode->left != NULL)
	{
		ConvertNode(PCurrentNode->left, PLastNode);
	}
	PCurrentNode->left = *PLastNode;
	if(*PLastNode != NULL)
	{
		(*PLastNode)->right = PCurrentNode;
	}
	*PLastNode = PCurrentNode;
	if(PCurrentNode->right != NULL)
	{
		ConvertNode(PCurrentNode->right, PLastNode);
	}
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode *PLastNode = NULL;
	ConvertNode(pRootOfTree, &PLastNode);
	TreeNode *PHeadNode = PLastNode;
	while(PHeadNode != NULL && PHeadNode->left != NULL)
	{
		PHeadNode = PHeadNode->left;
	}	

	return PHeadNode;
}

void show_left(struct TreeNode *head)
{
	TreeNode *p = head;
	while(p != NULL)
	{
		cout << p->val << " ";
		p = p->left;
	}
	cout << endl;
}

void show_right(struct TreeNode *head)
{
	TreeNode *p = head;
	while(p != NULL)
	{
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;
}

TreeNode *findend(TreeNode *head)
{
	TreeNode *p = head;
	while(p ->right != NULL)
	{
		p = p->right;
	}
	return p;	
}
int main()
{
	struct TreeNode *T;
	CreateTree(T);
	cout << "ok" << endl;
	struct TreeNode *hT = Convert(T);
	cout << "show right" << endl;
	show_right(hT);
	cout << "Convert ok" << endl;
	TreeNode *endi = findend(hT);
	cout << "end->val: " << endi->val <<  endl;
	show_left(endi);

	return 0;
}	
