#include <iostream>
using namespace std;

class queue
{
private:
	int* data, size, rear, front, capacity;
public:
	queue(int ent = 0) : capacity(ent)
	{
		data = new int[capacity];
		rear = front = size = 0;
	}
	~queue() {}
	void add(int item)
	{
		if (size < capacity)
		{
			cout << item << "   ";
			data[rear] = item;
			rear = (rear + 1) % capacity;
			size++;
			cout << " done!\n";
		}
		else
		{
			cout << "FULL\n";
		}
	}
	int get()
	{
		int temp = 0;
		if (size > 0)
		{
			temp = data[front];
			front = (front + 1) % capacity;
			size--;
			return temp;
		}
		else
		{
			cout << "EMPTY\n";
			return INT_MIN;
		}
	}
};

int main(void)
{
	queue ob1(10);
	for (int i = 0; i < 11; i++)
		ob1.add(i * i * i);
	for (int i = 0; i < 11; i++)
		cout << ob1.get() << endl;

	return 0;
}