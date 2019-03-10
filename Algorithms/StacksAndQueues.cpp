﻿#include "StacksAndQueues.h"

// 10.1-1 A ábrán bemutatott modell felhasználásával szemléltessük a Verembe(V,4),
// Verembe(V, 1), Verembe(V, 3), Veremb ˝ol(V), Verembe(V, 8) és Veremb˝ol(V) m˝uveletek
// mindegyikének a végrehajtását, ha a vermet a V[1 . . 6] tömbben tároljuk, és a verem kezdetben üres.

int _head = 0;

bool isEmpty()
{
	if (_head == 0)
		return true;
	else
		return false;
}

void push(int _stack[], int _element)
{
	if (_head < MAX01)
	{
		_stack[_head] = _element;
		++_head;
	}
	else
	{
		// overFlow
	}
}

int pop(int _stack[])
{
	if (isEmpty())
		return -1;
	else
	{
		int _localHead = _stack[_head];
		--_head;
		return _localHead;
	}
}

// 10.1-2 Hogyan valósítható meg két verem egyetlen A[1 . . n] tömbben úgy, hogy egyik verem
// sem csordul túl addig, amíg együttes elemszámuk nem haladja meg az n - et ? A Verembe
// és Veremb˝ol m˝uveletek végrehajtási ideje maradjon O(1).

int _headFirst = 0;
int _headSecond = MAX02;

bool isEmptyFirst() 
{
	if (_headFirst == 0)
		return true;
	else
		return false;
}

bool isEmptySecond()
{
	if (_headSecond == MAX02)
		return true;
	else
		return false;
}

bool isFull()
{
	if (_headFirst == _headSecond)
		return true;
	else
		return false;
}

void pushFirst(int _stack[], int _element)
{
	if (!isFull())
	{
		_stack[_headFirst] = _element;
		++_headFirst;
	}
	else
	{
		// overFlow
	}
		
}

void pushSecond(int _stack[], int _element)
{
	if (!isFull())
	{
		--_headSecond;
		_stack[_headSecond] = _element;
	}
	else
	{
		// overFlow
	}
}

int popFirst(int _stack[])
{
	if (!isEmptyFirst())
	{
		int retVal = _stack[_headFirst];
		--_headFirst;
		return retVal;
	}
	else
	{
		// underFlow
		return -1;
	}
}

int popSecond(int _stack[])
{
	if (!isEmptySecond())
	{
		int retVal = _stack[_headSecond];
		++_headSecond;
		return retVal;
	}
	else
	{
		// underFlow
		return -1;
	}
}

// 10.1-3. A 10.2. ábrán bemutatott modell felhasználásával szemléltessük a Sorba(S, 4),
// Sorba(S, 1), Sorba(S, 3), Sorb ´ol(S), Sorba(S, 8) és Sorb ´ol(S) m˝uveletek mindegyikének
// a végrehajtását, ha a sort a S[1 . . 6] tömbben tároljuk, és a sor kezdetben üres.

int _headQueue = 0;
int _tailQueue = 0;
int _sizeQueue = 0;

void pushBack(int _queue[], int _element) 
{
	if (_sizeQueue == MAX01)
	{
		// overFlow
	}
	else
	{
		_queue[_tailQueue] = _element;
		if (_tailQueue == MAX01 - 1)
			_tailQueue = 0;
		else
			_tailQueue++;
		_sizeQueue++;
	}
}

int popFront(int _queue[]) 
{
	if (_sizeQueue == 0)
	{
		// underFlow
		return -1;
	}
	else
	{
		int retVal = _queue[_headQueue];
		if (_headQueue == MAX01 - 1)
			_headQueue = 0;
		else
			_headQueue++;
		_sizeQueue--;
		return retVal;
	}
}
