﻿#pragma once

#include <iostream>
#include <vector>

#define MAX01 6
#define MAX02 20

// Task 01
class Stack
{
private:
	std::vector<int> stack;
	std::vector<int>::iterator head;
public:
	Stack();
	bool isEmpty();
	void push(int _element);
	int pop();
	int top();

};

// Task 02
class DoubleStack
{
private:
	std::vector<int> doubleStack;
	std::vector<int>::iterator headFirst;
	std::vector<int>::iterator headSecond;
public:
	DoubleStack();
	bool isEmptyFirst();
	bool isEmptySecond();
	bool isFull();
	void pushFirst(int _element);
	void pushSecond(int _element);
	int popFirst();
	int popSecond();
	int topFirst();
	int topSecond();

};

// Task 03

class Queue
{
private:
	std::vector<int> queue;
	std::vector<int>::iterator front;
	std::vector<int>::iterator back;
	bool isFull();
	int length = 0;
public:
	Queue();
	void pushBack(int _element);
	int popFront();
	bool isEmpty();
};

// Task 04

// Task 05
void pushDeqFront(int _deq[], int _element);
void pushDeqBack(int _deq[], int _element);
int popDeqFront(int _deq[]);
int popDeqBack(int _deq[]);

// Task 06


