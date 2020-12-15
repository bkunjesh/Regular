#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Queue
{
public:
	ll front, rear, size;
	ll capacity;
	ll* arr;
	Queue(ll capacity)
	{
		arr = new ll[capacity * sizeof(ll)];
		front = size = 0;
		rear = -1;
	}
	void enqueue(ll data)
	{
		if (size == capacity) return ;
		arr[(++rear) % capacity] = data;
		size++;
	}
	void dequeue()
	{
		if (size == 0) return;
		cout << arr[front] << endl;
		front = (front + 1) % capacity;
		size--;
	}
	int getfront()
	{
		cout << arr[front] << endl;
		return arr[front];
	}
	int getrear()
	{
		if (rear == -1) return INT_MIN;
		cout << arr[rear] << endl;
		return arr[rear];
	}

};
int main()
{
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.dequeue();
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.dequeue();
	q.getrear();
	q.getfront();
	q.enqueue(7);
	q.getrear();
	q.getfront();

}