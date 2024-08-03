#include <iostream>
using namespace std;

class stack
{
private:
	int* data, top, capacity;
public:
	stack(int ent = 0) : capacity(ent)
	{
		data = new int[capacity];
		top = 0; 
	}
	void add(int item)
	{
		if (top < capacity)
			data[top++] = item;
		else
			cout << "FULL\n";
	}
	int get()
	{
		if (top == 0)
		{
			cout << "EMPTY\n";
			return INT_MIN;
		}
		else
		{
			int temp = 0;
			temp = data[--top];
			return temp;
		}
	}

};

int main(void)
{
	stack ob(10);
	for (int i = 0; i < 12; i++)
		ob.add(i * i);

	cout << endl;
	for (int i = 0; i < 12; i++)
		cout << ob.get() << endl;

	return 0;
}