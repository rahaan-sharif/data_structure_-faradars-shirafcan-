#include <iostream>
using namespace std;

void quick_sort(int a[], int start, int end)
{
	if (start >= end)
		return;


	int* less = new int[ (end - start + 1) ], l = 0;
	int* more = new int[ (end - start + 1) ], m = 0;
	int item = a[end], loc = end;


	for (int i = start; i < end; i++)
	{
		if (a[i] > a[end])
			more[m++] = a[i];
		else if (a[i] < a[end])
			less[l++] = a[i];
	}

	for (int i = 0; i < l; i++)
		a[i + start] = less[i];
	loc = l;
	a[loc + start] = item;
	for (int j = 0; j < m; j++)
		a[l + j + 1 + start] = more[j];

	delete[]more;
	delete[]less;

	quick_sort(a, start, start+loc - 1);
	quick_sort(a, loc + 1 + start, end);

}

int main(void)
{
	cout << "salam" << endl;
	int a[] = { 4,3,8,6,1,9,5,2,7 };
	quick_sort(a, 0, 8);
	for (int i = 0; i < 9; i++)
		cout << a[i] << ", ";


	return 0;
}