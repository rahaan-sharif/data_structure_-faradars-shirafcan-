#include <iostream>
using namespace std;

class node
{
private:
	int data;
	node* next;
public:
	node()
	{
		data = 0;
		next = NULL;
	}
	node(node*& start, int value)  
	{
		data = value;
		next = NULL;
		if (start == NULL)
		{
			start = this;
			return;
		}
		
		node* n = start;
		while (n->next != NULL)
			n = n->next;
		n->next = this;
	}
	~node(){}
	void show_list(node*& start)
	{
		node* n = start;
		while (n != NULL)
		{
			cout << n->data<<"->";
			n = n->next;
		}
		cout << "NULL\n";
	}
	static int delete_item(node*& start, int item)
	{
		node* n = start;
		int value = -1;
		node *temp;
		if (start->data == item)
		{
			temp = start;
			value = start->data;
			start = start->next;
			temp->~node();
			return value;
		}

		while (n != NULL)
		{
			if ((n->next)->data == item)
			{
				temp = n->next;
				value = temp->data;
				n->next = (n->next)->next;
				temp->~node();
				return value;
			}
			n = n->next;
		}
	}
	static int get_end(node*& start) 
	{
		node* temp = start;
		if (temp == NULL)
		{
			cout << "EMPTY_STACK\n";
			return INT_MIN;
		}
		if (temp->next == NULL)
		{
			start->next=NULL;
			start->data = -1;
			return temp->data;
		}
		while (temp->next->next != NULL)
			temp = temp->next;
		int value = temp->next->data;
		temp->next = NULL;
		return value;
	}
	static int get_start(node*& start) 
	{
		if (start == NULL)
		{
			cout << "empty linked_list\n";
			return INT_MIN;
		}
		int value = start->data;
		node* temp = start;
		start = start->next;
		return value;
	}
};

class queue 
{
private:
	int capacity, front, size;
	node* start0;
public:
	static void create(queue*& start1, int value)
	{
		start1->capacity = value;
		start1->front = start1->size = 0;
	}
	queue() {}
	queue(queue*& start1, int value)
	{
		if (start1->size < start1->capacity)
		{
			new node(start1->start0, value);
			start1->size++;
			return;
		}
		cout << "FULL\n";
		
	}
	~queue() {}  //this function is not completed. this is for deleting whole queue. 
	static int output(queue*& start1)
	{
		int value = start1->start0->get_start(start1->start0);
		start1->size--;
		return value;
	}
};


class stack
{
private:
	int top;
	node* start0;
public:
	static void create(stack*& start1)
	{
		start1->top = 0;
	}
	stack() {}
	stack(stack*& start1, int value)
	{
		new node(start1->start0, value);
		start1->top++;
	}
	~stack() {}
	static int output(stack*& start1) 
	{
		int value = start1->start0->get_end(start1->start0);
		start1->top--;
		return value;
	}
};


int main(void)
{
	cout << "linked_list: " << endl;
	node* start = NULL;
	node ob1(start, 10), ob2(start, 11), ob3(start, 13), ob4(start, 15), ob5(start, 112);
	int item= node::delete_item(start, 13);
	start->show_list(start);
	cout << "item: " << item << endl;
	cout << endl << endl;

	queue* start1 = NULL;
	start1 = new queue;
	start1->create(start1, 10);
	queue ob11(start1, 11), ob22(start1, 12), ob33(start1, 13);
	int item2 = start1->output(start1);
	cout << "item2: " << item2 << endl;
	item2 = start1->output(start1);
	cout << "item2: " << item2 << endl;
	cout << endl << endl;

	stack* start2 = NULL;
	start2 = new stack;
	start2->create(start2);
	stack oc1(start2, 1), oc2(start2, 2), oc3(start2, 3), oc4(start2, 4);
	int item3 = start2->output(start2);
	cout << "item3: " << item3 << endl;
	item3 = start2->output(start2);
	cout << "item3: " << item3 << endl;


	return 0;
}