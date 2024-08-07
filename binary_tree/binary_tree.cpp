#include <iostream>
using namespace std;

class bt
{
private:
	int data;
public:
	bt* left, * right;
	~bt() {}
	void create(bt*& start, int item)
	{
		start = new bt;
		start->data = item;
		start->left = NULL;
		start->right = NULL;
	}
	void show()
	{
		cout << data << "   ";
		if (left ==NULL && right == NULL)
			cout << "leafe" << endl;
		else
			cout << "node\n";
	}
	int height(bt* start)
	{
		if (start == NULL)
			return -1;
		if (start->left == NULL && start->right == NULL)
			return 0;
		int lh = height(start->left);
		int rh = height(start->right);
		if (lh > rh)
			return lh + 1;
		else
			return rh + 1;
	}
	int count_leaf(bt*& start)
	{
		if (start == NULL)
			return 0;
		else if (start->left == NULL && start->right == NULL)
			return 1;
		else
			return (count_leaf(start->left) + count_leaf(start->right));
	}
	int count_nodes(bt*& start)
	{
		if (start == NULL)
			return 0;
		else
			return 1 + count_nodes(start->left) + count_nodes(start->right);
	}
	void del_tree(bt*& start)
	{
		if (start == NULL)
		{
			return;
		}
		del_tree(start->left);
		del_tree(start->right);
		cout << start->data << endl;
		delete start;
	}
	int max(bt*& start, int ent=INT_MIN)
	{
		if (start == NULL)
			return INT_MIN;
		int a = max(start->left);
		cout << "* " << a << endl;
		int b = max(start->right);
		cout << " * " << b << endl;
		int max = a;
		if (max < b)
			max = b;
		if (max > start->data)
			return max;
		else
			return start->data;
	}
};

int main(void)
{
	bt* root = NULL;
	root->create(root, 10);
	root->right->create(root->right, 100);
	root->right->left->create(root->right->left, 2);
	root->right->left->left->create(root->right->left->left, 20);
	root->left->create(root->left, 3);
	root->show();
	cout << endl;

	cout << "height of root: " << root->height(root) << endl;
	cout << "count_leaves: " << root->count_leaf(root) << endl<<endl;

	cout << "max: " << root->max(root) << endl << endl;


	cout << "\n\ndeleting: " << endl;
	root->del_tree(root);
	cout << "-----\n";
	root->show();

	return 0;
}
