#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
	ll data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class Linkedlist
{
public:

	Node* head;

	Linkedlist()
	{
		head = NULL;
	}
	void append(ll data)
	{
		Node* newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			return ;
		}
		Node* cur = head;
		while (cur->next != NULL) cur = cur->next;
		cur->next = newnode;
	}
	void reverse()
	{
		Node* prev = NULL;
		Node* cur = head;
		Node* next = head;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
	}
	void print()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void push(int data)
	{
		Node* newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			return ;
		}
		newnode->next = head;
		head = newnode;
	}
	void recreverse(Node* prev, Node* cur)
	{
		if (cur == NULL)
		{
			head = prev;
			return ;
		}
		Node* next = cur->next;
		cur->next = prev;
		recreverse(cur, next);
	}
	void recursivereverse()
	{
		Node* cur = head;

		recreverse(NULL, cur);
	}
	void middle()
	{
		Node* fast = head;
		Node* slow = head;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		cout << slow->data << endl;

	}
	void nthelementfromend(int n)
	{
		Node* first = head;
		Node* second = head;
		while (n--) second = second->next;
		while (second != NULL) second = second->next, first = first->next;

		cout << first->data << endl;
	}
	void makeYintersection(Node* b, ll n)
	{
		Node* b_head = b;
		Node* a_head = head;
		while (b_head->next != NULL) b_head = b_head->next;
		while (n-- && a_head->next != NULL) a_head = a_head->next;
		b_head->next = a_head;
	}
	void findYintersection(Node* b)
	{
		Node* b_head = b;
		Node* a_head = head;
		ll a_cnt = 0, b_cnt = 0;
		while (b_head->next != NULL) b_head = b_head->next, b_cnt++;
		while (a_head->next != NULL) a_head = a_head->next, a_cnt++;
		ll diff = abs(a_cnt - b_cnt);

		b_head = b;
		a_head = head;
		if (a_cnt > b_cnt)	while (diff--) a_head = a_head->next;
		else while (diff--) b_head = b_head->next;

		while (a_head != b_head) a_head = a_head->next, b_head = b_head->next;

		cout << a_head->data << endl;
	}
	void ispallindrom()
	{
		stack<ll> s;
		Node* a = head;
		while (a != NULL)
		{
			s.push(a->data);
			a = a->next;
		}
		a = head;
		while (!s.empty())
		{
			ll temp = s.top();
			s.pop();
			if (a->data != temp) break;
			a = a->next;
		}
		if (!s.empty()) cout << "NOT PALLINDROM" << endl;
		else cout << "PALLINDROM" << endl;
	}
	Node* reversegroup(Node *head, ll k)
	{
		//3.	Reverse a LinkedList in groups.
		//dekhana padega fir se
		Node* cur = head;
		Node* next = head;
		Node* pre = NULL;
		ll cnt = 0;
		while (cur != NULL && cnt < k)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
			cnt++;
		}
		if (cur != NULL)
			head->next = reversegroup(next, k);

		return pre;
	}
	void makecyclfromYintersection(Node* b)
	{
		Node* a = head;
		while (a->next != NULL) a = a->next;
		a->next = b;
	}
	void detectcycle_remove()
	{
		Node* fast = head;
		Node* slow = head;
		fast = fast->next->next;
		slow = slow->next;
		while (fast != slow && fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		if (fast == NULL || fast->next == NULL) cout << "NO CYCLE DETECT" << endl;
		else
		{
			//cout << slow->data << endl;
			cout << "cycle detect" << endl << "removing cycle..." << endl;
			fast = head;
			while (slow->next != fast->next) slow = slow->next, fast = fast->next;
			slow->next = NULL;
			cout << "cycle removed" << endl;
		}
		print();
	}
	void rotate(ll n)
	{
		Node* last = head;
		Node* nth = head;
		ll len = 1;
		while (last->next != NULL) last = last->next, len++;
		n = n % len;
		//cout << n << endl;
		if (n == 0)
		{
			print();
			return ;
		}
		while (--n) nth = nth->next;
		last->next = head;
		head = nth->next;
		nth->next = NULL;
		print();
	}


};


int main()
{
	Linkedlist ll1, ll2;
	ll1.append(2);
	ll1.append(6);
	ll1.append(5);
	ll1.push(1);
	ll1.append(3);
	ll1.append(4);
	ll1.print();
	ll1.reverse();
	ll1.print();
	ll1.recursivereverse();
	ll1.print();
	ll1.middle();
	ll1.nthelementfromend(1);
	ll2.append(4);
	ll2.append(3);
	ll2.append(5);
	ll1.makeYintersection(ll2.head, 2);
	ll2.print();
	ll1.findYintersection(ll2.head);
	ll2.ispallindrom();
	ll1.print();
	ll1.head = ll1.reversegroup(ll1.head, 2);
	ll1.print();
	ll1.head = ll1.reversegroup(ll1.head, 2);
	ll2.print();
	ll1.makecyclfromYintersection(ll2.head);
	ll1.detectcycle_remove();
	ll1.rotate(9);
	//ll1.addition();
}
