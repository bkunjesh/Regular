#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
	int i = 0, j = 0;
	int n1 = m - l + 1, n2 = r - m;
	int left[n1], right[n2];
	for (int k = l; k <= m; k++)
		left[k - l] = a[k];
	for (int k = m + 1; k <= r; k++)
		right[k - m - 1] = a[k];
	int k = l;
	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
		{
			a[k++] = left[i++];
		}
		else
		{
			a[k++] = right[j++];
		}
	}
	while (i < n1) a[k++] = left[i++];
	while (j < n2) a[k++] = right[j++];


}
void split(int a[], int l, int r)
{
	if (r - l < 1) return ;
	int mid = l + (r - l) / 2;
	split(a, l, mid);
	split(a, mid + 1, r);

	merge(a, l, mid, r);

}
void mergesort(int a[], int n)
{
	split(a, 0, n - 1);
}
int main()
{
	int a[] = {100, 3, 4, 6, 2, 6, 5, 1, 10};
	int n = sizeof(a) / sizeof(a[0]);
	mergesort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;


}