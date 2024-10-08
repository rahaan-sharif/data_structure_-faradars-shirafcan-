#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* add_begin(node* s, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = s;
	return temp;
}

void show(node* s)
{
	node* temp = new node;
	temp = s;

	if (temp == NULL)
	{
		cout << "NULL\n";
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout << endl;
}

void search_nore(node* s, int data)
{
	//look if we can brief the two lines below:
	node* temp = s;
	int counter=0;
	bool check = 0;

	while (temp->next != NULL)
	{
		if (temp->data == data)
		{
			cout << "found in " << counter;
			check = 1;
		}
		counter++;
		temp = temp->next;
	}
	if (!check)
		cout << "not found!\n";
}

void search_rec(node* s, int data)
{
	static int counter = 0;
	if (s == NULL)
	{
		cout << "not found\n";
		return;
	}
	else if (s->data == data)
	{
		cout << data<<" found in " << counter << endl;
		show(s);
		return;
	}
	counter++;
	search_rec(s->next, data);
}
///

int main(void)
{
	node* root = new node;
	root->data = 0;
	root->next = NULL;
	for (int i = 0; i < 10; i++)
		root=add_begin(root, i);
	show(root);
	search_nore(root, 4);
	cout << endl << endl << endl;

}



