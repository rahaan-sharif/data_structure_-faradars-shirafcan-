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
	int find_level(tree* start, int item, int level=0)
	{
		if (start == NULL)
			return -1;
		if (start->data == item)
			return level;
		int a = 0, b = 0;
		a = find_level(start->right, item, level + 1);
		b = find_level(start->left, item, level + 1);
		return (a > b) ? a : b;
	}


};

int main(void)
{
	tree* root = tree::create(1);
	root->right = tree::create(2);
	root->left = tree::create(3);
	root->left->left = tree::create(4);
	root->right->right = tree::create(5);
	root->right->right->right = tree::create(6);

	cout<<root->find_level(root, 6);



	return 0;
}