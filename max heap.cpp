#include<bits/stdc++.h>
using namespace std;

int n;

void heapify(int a[], int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int greatest = i;
	if (l < n && a[i] < a[l])
		greatest = l;
	if (r < n && a[r] > a[greatest])
		greatest = r;
	if (i != greatest)
	{
		swap(a[i], a[greatest]);
		heapify(a, greatest);
	}

}

void build_max_heap(int a[])
{
	for (int i = floor(n / 2) - 1 ; i >= 0; i--)
	{
		heapify(a, i);
	}
}

int extract_max(int a[])
{
	if (n < 1)
	{
		return INT_MIN;
	}
	int mx = a[0];
	a[0] = a[n - 1];
	n--;
	heapify(a, 0);

	return mx;
}
void increase_key(int a[], int i, int key)
{
	if (key <= a[i]) return ;
	a[i] = key;
	int parent = (i - 1) / 2;
	while (parent >= 0 && a[i] > a[parent])
	{
		swap(a[parent], a[i]);
		i = parent;
		parent = (i - 1) / 2;
	}

}
void heap_sort(int a[])
{
	build_max_heap(a);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[i], a[0]);
		heapify(a, 0);
	}

}

int main()
{
	int a[] = {3, 1, 5, 6, 8, 9, 2};
	n = sizeof(a) / sizeof(a[0]);

	build_max_heap(a);

	cout << extract_max(a) << endl;

	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;

	increase_key(a, 3, 10);

	heap_sort(a);

	for (int i = 0; i < n; i++) cout << a[i] << " ";

}