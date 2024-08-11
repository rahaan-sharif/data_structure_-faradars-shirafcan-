//binary search tree نمایش میانوندی یک درخت 
#include <iostream>
using namespace std;

class queue
{
private:
	int rear, front, capacity;
	int arr[10];
public:
	queue() : rear(0), front(0), capacity(0)
	{
		for (int i = 0; i < 10; i++)
			arr[i] = 0;
	}
	void set(int item) 
	{
		arr[rear] = item; 
		rear = (rear + 1) % (10);
		capacity++;
	}
	bool is_full()
	{
		if (capacity<=10 && capacity>0)
			return 1;
		else
			return 0;
	}
	int get() 
	{ 
		int temp = arr[front];
		front = (front + 1) % 10;
		capacity--;
		return temp; 
	}
};

class bst
{
private:
	int data;
public:
	bst* left, * right;
	void create(bst*& root, int item) 
	{
		if (root == NULL)
		{
			root = new bst;
			root->data = item;
			root->left = NULL;
			root->right = NULL;
			return;
		}
		if (item > root->data)
			create(root->right, item);
		else if (item < root->data)
			create(root->left, item);
	}

	void saving(queue& block)
	{
		if (this == NULL)
			return;
		left->saving(block);
		block.set(data);
		right->saving(block);
	}

	void show(bst* root)
	{
		queue block;
		root->saving(block);
		while (block.is_full())
			cout << block.get() << ", ";
	}
	
};

int main(void)
{
	bst* root=NULL;
	root->create(root, 10);
	root->create(root, 5);
	root->create(root, 15);
	root->create(root, 14);
	root->create(root, 20);

	root->show(root);



	return 0;
}