#pragma once

#include <iostream>

// Task 01
#define MAX01 6
bool isEmpty();
void push(int _stack[], int _element);
int pop(int _stack[]);

// Task 02
#define MAX02 20
bool isEmptyFirst();
bool isEmptySecond();
bool isFull();
void pushFirst(int _stack[], int _element);
void pushSecond(int _stack[], int _element);
int popFirst(int _stack[]);
int popSecond(int _stack[]);

// Task 03
void pushBack(int _queue[], int _element);
int popFront(int _queue[]);

