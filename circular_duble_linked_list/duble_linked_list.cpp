#include <iostream>
using namespace std;

class dll     //duble linked list
{
private:
	int data;
	dll* next, * prev;
public:
	void create(dll*& start, int item)
	{
		start = new dll;
		start->data = item;
		start->next = start;
		start->prev = start;
	}
	dll() {}
	dll(dll*& start, int item) : data(item)
	{
		dll* temp = start;
		while (temp->next != start)
			temp = temp->next;
		temp->next = this;
		next = start;
		prev = temp;
	}
	void show(dll* start)
	{
		if (start == NULL)
		{
			cout << "empty\n";
			return;
		}
		dll* temp = start;
		do 
		{
			cout << temp->data << " <-> ";
			temp = temp->next;
		} while (temp != start );
		cout << "NULL\n";
	}
	int del(dll*& start)
	{
		int temp = start->data;
		start->prev->next = start->next;
		start->next->prev = start->prev;
		start = start->next;
		return temp;
	}
};

int main(void)
{
	dll* start = NULL;
	start->create(start, 0);
	dll ob1(start, 1), ob2(start, 2), ob3(start, 3);
	start->show(start);

	cout << "***\n";
	cout << "item 1: " << start->del(start) << endl;
	cout << "item 2: " << start->del(start) << endl;


	return 0;
}