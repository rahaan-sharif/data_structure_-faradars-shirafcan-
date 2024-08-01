#include <iostream>
using namespace std;

class person
{
private:
	int data;
	person* next;
public:
	static void create(person*& start)
	{
		if (start == NULL)
		{
			start = new person;
			start->data = 1;
			start->next = start;
		}
		else
		{
			person* temp = start;
			while (temp->next != start)
				temp = temp->next;
			person* temp2 = new person;
			temp2->data = temp->data + 1;
			temp->next = temp2;
			temp2->next = start;
		}
	}
	person(){}
	~person(){}
	static void delete_person(person*& start)
	{
		person* temp = start->next;
		if (temp == start)
		{
			cout << "just one remained: " << start->data << endl;
			return;
		}
		start->next = start->next->next;
		start = start->next;
		temp->~person();
	}

};

int main(void)
{
	person* start=NULL;
	for (int i = 0; i < 41; i++)
		person::create(start);
	for (int i = 0; i < 41; i++)
		person::delete_person(start);

	return 0;
}