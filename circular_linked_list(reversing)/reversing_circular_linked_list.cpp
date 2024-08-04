#include <iostream>
using namespace std;

class c_linked_list
{
private:
	int data;
	c_linked_list* next;
public:
	void make(c_linked_list*& start, int item)
	{
		start = new c_linked_list;
		start->data = item;
		start->next = start;
	}
	c_linked_list() {}
	c_linked_list(c_linked_list*& start, int item = 0) : data(item)
	{
		c_linked_list* temp = start;
		while (temp->next != start)
			temp = temp->next;
		temp->next = this;
		this->next=start;
	}
	void show(c_linked_list*& start)
	{
		c_linked_list* temp = start;
		if (temp == NULL)
		{
			cout << "NULL\n";
			return;
		}
		while (temp->next != start)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
	void reverse(c_linked_list*& start)
	{
		c_linked_list* temp1=start, * temp2=temp1->next, * temp3=temp2->next;
		if (start->next == start)
			return;
		if (start->next->next == start)
		{
			start = start->next;
			return;
		}
		while (temp3->next != start)
		{
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp3;
			temp3 = temp3->next;
		}
		temp3->next = temp2;
		temp2->next = temp1;
		start->next = temp3;
		start = temp3;
	}
};


int main(void)
{
	c_linked_list* start = NULL;
	start->make(start, 0);
	c_linked_list ob1(start, 1), ob2(start, 2), ob3(start, 3);
	start->show(start);
	start->reverse(start);
	start->show(start);

	return 0;
}