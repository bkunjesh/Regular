#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node
{
public:
	ll data;
	Node* next;
	Node(ll data)
	{
		this->data = data;
		next = NULL;
	}

};
class Stack
{
public:
	Node* head;
	Stack()
	{
		head = NULL;
	}
	void push(ll data)
	{
		Node* newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			return;
		}
		newnode->next = head;
		head = newnode;
	}
	void pop()
	{
		if (head == NULL) return ;
		Node* temp = head;
		head = head->next;
		free(temp);
	}
	ll top()
	{
		if (head == NULL) return INT_MIN;
		return head->data;
	}


};

int main()
{
	Stack s;
	s.push(4);
	s.push(3);
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

}