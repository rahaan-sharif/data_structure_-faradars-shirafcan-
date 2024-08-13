#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
	int temp = 0; 

	for (int i = 1; i < n; i++)
	{

		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}

		}

	}
}


int main(void)
{
	int a[10] = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	insertion_sort(a, 10);

	for (int k = 0; k < 10; k++)
		cout << a[k] << ", ";
	cout << endl;


	return 0;
}