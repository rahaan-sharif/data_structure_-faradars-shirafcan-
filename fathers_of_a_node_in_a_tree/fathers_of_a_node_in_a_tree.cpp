#include <iostream>
using namespace std;

class tree
{
private:
	int data;
public:
	tree* left, * right;

	static tree* create(int item)
	{
		tree* temp = new tree;
		temp->data = item;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}

	bool fathers(tree* start, int item, int*& output)
	{
		static int j = 0;
		if (start == NULL)
			return 0;
		if (start->data == item)
			return 1;
		if(fathers(start->right, item, output) || fathers(start->left, item, output))
			output[j++]=start->data;
	}
};

int main(void)
{
	tree* root = tree::create(1);
	root->right = tree::create(2);
	root->left= tree::create(3);
	root->right->right= tree::create(4);
	root->right->left= tree::create(5);
	root->left->left= tree::create(6);
	root->left->right= tree::create(7);
	root->right->right->right= tree::create(8);

	int *a=new int [10];
	for (int i = 0; i < 10; i++)
		a[i] = -1;

	root->fathers(root, 8, a);
	for (int i = 0; i < 10; i++)
		if (a[i] != -1)
			cout << a[i] << "  ";




	return 0;
}