#pragma once

#include <iostream>
#include <vector>

#define MAX01 6
#define MAX02 20

// Task 01
class Stack
{
private:
	std::vector<int> stack[MAX01];
	std::vector<int>::iterator head = stack->begin();
public:
	bool isEmpty();
	void push(int _element);
	int pop();

};

// Task 02
class DoubleStack
{
private:
	std::vector<int> doubleStack[MAX02];
	std::vector<int>::iterator headFirst = doubleStack->begin();
	std::vector<int>::iterator headSecond = doubleStack->end();
public:
	bool isEmptyFirst();
	bool isEmptySecond();
	bool isFull();
	void pushFirst(int _element);
	void pushSecond(int _element);
	int popFirst();
	int popSecond();

};

// Task 03
void pushBack(int _queue[], int _element);
int popFront(int _queue[]);

// Task 04

// Task 05
void pushDeqFront(int _deq[], int _element);
void pushDeqBack(int _deq[], int _element);
int popDeqFront(int _deq[]);
int popDeqBack(int _deq[]);

// Task 06


