#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void addNode(int key, int value)
    {
        Node *newNode = new Node(key, value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *currentNode = head;
        while (currentNode->key != key && currentNode->next != NULL)
            currentNode = currentNode->next;
        if (currentNode->key == key)
        {
            currentNode->value = value;
            delete newNode;
            return;
        }
        currentNode->next = newNode;
    }

    void remove(int key)
    {
        if (head == NULL)
            return;
        Node *currentNode = head;
        Node *prevNode = head;

        if (head->key == key)
        {
            head = head->next;
            delete currentNode;
            return;
        }

        while (currentNode != NULL && currentNode->key != key)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode != NULL && currentNode->key == key)
        {
            prevNode->next = currentNode->next;
            delete currentNode;
        }
    }

    int get(int key)
    {
        Node *currentNode = head;
        while (currentNode != NULL && currentNode->key != key)
            currentNode = currentNode->next;

        if (currentNode == NULL)
            return -1;

        return currentNode->value;
    }
    void print()
    {
        Node *currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->key << " " << currentNode->value << endl;
            currentNode = currentNode->next;
        }
    }
};

class MyHashMap
{
public:
    vector<LinkedList> map;
    int size = 1000;
    MyHashMap()
    {
        map.resize(size);
    }
    //add an element into map

    void put(int key, int value)
    {
        int bucket = key % size;
        LinkedList &list = map[bucket];
        list.addNode(key, value);
    }

    int get(int key)
    {
        int bucket = key % size;
        LinkedList &list = map[bucket];
        return list.get(key);
    }

    void remove(int key)
    {
        int bucket = key % size;
        LinkedList &list = map[bucket];
        list.remove(key);
        // list.print();
    }
};

int main()
{
    MyHashMap m;
    m.put(1, 2);
    m.put(5, 9);
    m.put(1005, 10);
    m.remove(5);
    cout << endl;
    cout << m.get(1) << " " << m.get(5) << endl;
}