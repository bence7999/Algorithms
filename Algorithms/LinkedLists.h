#pragma once

#include <iostream>

// Task 01

class Node
{
	int data;
public:
	explicit Node(int _data);
	~Node();
	Node* next = nullptr;
	Node* prev = nullptr;
	int getData();
};

class DoublyLinkedList
{
public:
	~DoublyLinkedList();
	Node* head = nullptr;
	void add(int _data);
	void remove(Node* node);
	Node* search(int _data);
	bool isEmpty();
	
	static int counter;
};

// Task 02

class StackUsingLinkedList
{
	DoublyLinkedList ll;
	int length = 0;
public:
	bool isEmpty();
	void push(int _element);
	int pop();
	int top();
};

// Task 03

class QueueUsingLinedList
{
	DoublyLinkedList ll;
	Node* tail = nullptr;
public:
	void pushBack(int _data);
	int popFront();
	bool isEmpty();
};

// Task 04

