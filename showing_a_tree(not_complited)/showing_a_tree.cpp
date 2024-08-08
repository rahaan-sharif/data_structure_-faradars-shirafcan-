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
		start->left = NULL;
		start->right = NULL;
	}
	void show(tree* start, int item=-1, int check=-1)
	{
		static char ch[100]={0};
		static int j = 0; 

		if (start == NULL)
			return;
		if (check == 0)
			cout << endl;
		int count = 0+item;
		tree* temp = start;
		while (temp != NULL)
		{
			temp = temp->left;
			count++;
		}
		for (int i = 0; i < 2 * count; i++)
			cout << " ";
		cout << start->data;

		//ch[j++] = '\n';
		for (int i = 0; i < 2 * count - 1; i++)
			ch[j++]=' ';
		ch[j++] = '/';
		ch[j++] = ' ';
		ch[j++] = '\\';

		if (check == 1 || check == -1)
		{
			cout << endl << ch << endl;
			for (int i = 0; i < j; i++)
				ch[i] = 0;
			j = 0;
		}
		show(start->left, count - 2, 0);
		show(start->right, count, 1);
	}
};

int main(void)
{
	tree* root = NULL;
	root->create(root, 1);
	root->left->create(root->left, 2);
	root->right->create(root->right, 3);
	root->left->left->create(root->left->left, 4);
	root->left->right->create(root->left->right, 5);
	root->show(root);


	return 0;
}