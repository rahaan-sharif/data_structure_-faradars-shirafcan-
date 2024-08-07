#include <iostream>
using namespace std;

class bt;
class bt_stack;

class bt_stack
{
private:
	int top;
	bt* location[100];
public:
	bt_stack()
	{
		top = 0;
		for (int i = 0; i < 100; i++)
			location[i] = NULL;
	}
	bool is_full()
	{
		if (top)
			return 1;
		else
			return 0;
	}
	void add(bt*& object)
	{
		location[top++] = object;
	}
	bt* give()
	{
		if (top != 0)
			return location[top--];
		else
			return NULL;
	}
};

class bt
{
private:
	int data;
public:
	bt* left, * right;
	void create(bt*& start, int item)
	{
		start = new bt;
		start->data = item;
		start->left = NULL;
		start->right = NULL;
	}
	void scrolling(bt* start)
	{
		bt* root = start;
		bt* x = NULL;
		bt_stack s;
		do {
			while (root != NULL)
			{
				s.add(root);
				root = root->left;
			}
			if (s.is_full())
			{
				x = s.give();
				if (x != NULL)
					cout << x->data << endl;
				else
					cout << "NULL" << endl;
				root = x->right;
			}
		} while (!(root == NULL && !s.is_full()));
	}
};




int main(void)
{
	bt* start = NULL;
	start->create(start, 1);
	start->right->create(start->right, 2);
	start->left->create(start->left, 3);
	start->right->right->create(start->right->right, 4);
	start->scrolling(start);

	return 0;
}