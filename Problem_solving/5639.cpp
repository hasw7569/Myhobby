#include<stdio.h>
struct EDGE
{
	int val = 0;
	EDGE* left = NULL;
	EDGE* right = NULL;
};
struct Binary_Tree
{
	EDGE* Root = NULL;
	void insert(int val)
	{
		if (Root == NULL)
		{
			Root = new EDGE;
			Root->val = val;
		}
		else
		{
			EDGE* next = Root;
			while (1)
			{
				if (next->val > val)
				{
					if (next->left == NULL)
					{
						next->left = new EDGE;
						next->left->val = val;
						break;
					}
					else
					{
						next = next->left;
					}
				}
				else
				{
					if (next->right == NULL)
					{
						next->right = new EDGE;
						next->right->val = val;
						break;
					}
					else
					{
						next = next->right;
					}
				}
			}
		}
	}
};
void inorder(EDGE* curr)
{
	if (curr->left != NULL)
	{
		inorder(curr->left);
	}
	if (curr->right != NULL)
	{
		inorder(curr->right);
	}
	printf("%d\n", curr->val);
}
int main()
{
	Binary_Tree BT;
	int temp;
	while (scanf("%d", &temp) != EOF)
	{
		BT.insert(temp);
	}
	inorder(BT.Root);
	return 0;
}