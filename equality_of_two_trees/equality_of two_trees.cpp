#include <iostream>
using namespace std;

class tree
{
private:
	int data;
public:
	tree* left, * right;
	void create(tree*& start, int item)
	{
		start = new tree;
		start->data = item;
		start->right = NULL;
		start->left = NULL;
	}
	static bool is_equal(tree* start1, tree* start2)
	{
		if (start1 == NULL && start2 == NULL)
			return 1;
		if (start1 != NULL && start2 != NULL)
			return ((start1->data == start2->data) && is_equal(start1->left, start2->left)
				&& is_equal(start1->right, start2->right));
		return 0;
	}
};


int main(void)
{
	tree* root1 = NULL;
	tree* root2 = NULL;

	root1->create(root1, 1);
	root1->right->create(root1->right, 2);
	root1->left->create(root1->left, 3);
	root1->left->left->create(root1->left->left, 4);

	root2->create(root2, 1);
	root2->right->create(root2->right, 2);
	root2->left->create(root2->left, 3);
	root2->left->left->create(root2->left->left, 4);

	cout << tree::is_equal(root1, root2);
	return 0;
}