#pragma once

#include <iostream>

// Task 01

class Node
{
	int data;
public:
	Node(int _data);
	~Node();
	Node* next;
	int getData();
};

class LinkedList
{
public:
	~LinkedList();
	Node* head = nullptr;
	void add(int _data);
	int remove(int _data);
	int removeFront(int _data);
	int removeBack(int _data);
	Node* search(int _data);
	bool isEmpty();
	
	static int counter;
};

// Task 02

class StackUsingLinkedList
{
	LinkedList ll;
	int length = 0;
public:
	bool isEmpty();
	void push(int _element);
	int pop();
	int top();
};