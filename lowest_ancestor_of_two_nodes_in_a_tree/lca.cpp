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
	tree* lca(int a, int b, bool& fa, bool& fb)
	{
		if (this == NULL)
			return NULL;
		if (data == a)
		{
			fa = true;
			return this;
		}
		if (data == b)
		{
			fb = true;
			return this;
		}
		tree* l_lca, * r_lca;
		l_lca = left->lca(a, b, fa, fb);
		r_lca = right->lca(a, b, fa, fb);
		if (l_lca && r_lca)
			return this;

		return (l_lca != NULL) ? l_lca : r_lca;
	}
	bool find(int item)
	{
		if (this == NULL)
			return false;
		if (data == item || left->find(item) || right->find(item))
			return true;
		return false;
	}
	tree* f(int a, int b)
	{
		bool fa = false, fb = false;
		tree* temp = NULL;
		if(find(a))
			if(find(b))
				temp = lca(a, b, fa, fb);
		return temp;
	}
	int get()
	{
		return data;
	}
};

int main(void)
{
	tree* root;
	root= tree::create(0);
	root->right= tree::create(1);
	root->left= tree::create(2);
	root->right->right= tree::create(3);
	root->right->left= tree::create(4);
	root->left->right= tree::create(5);
	root->left->left= tree::create(6);

	cout << root->f(4,3)->get() << endl;


	return 0;
}