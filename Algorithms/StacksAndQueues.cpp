#include "StacksAndQueues.h"

// Task 01

Stack::Stack()
{
	stack = std::vector<int>(MAX01);
	head = stack.begin();
}

bool Stack::isEmpty()
{
	if (head == stack.begin())
		return true;
	else
		return false;
}

void Stack::push(int _element)
{
	if (head != stack.end())
	{
		*head = _element;
		head++;
	}
	else
	{
		// overFlow
	}
}

int Stack::pop()
{
	if (isEmpty())
		return -1;
	else
	{
		int _localHead = *(head-1);
		head--; 
		return _localHead;
	}
}

int Stack::top()
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		return *(head-1);
	}
}

// Task 02

DoubleStack::DoubleStack()
{
	doubleStack = std::vector<int>(MAX02);
	headFirst = doubleStack.begin();
	headSecond = doubleStack.end();
}

bool DoubleStack::isEmptyFirst()
{
	if (headFirst == doubleStack.begin())
		return true;
	else
		return false;
}

bool DoubleStack::isEmptySecond()
{
	if (headSecond == doubleStack.end())
		return true;
	else
		return false;
}

bool DoubleStack::isFull()
{
	if (headFirst == headSecond)
		return true;
	else
		return false;
}

void DoubleStack::pushFirst(int _element)
{
	if (!isFull())
	{
		*headFirst = _element;
		headFirst++;
	}
	else
	{
		// overFlow
	}
		
}

void DoubleStack::pushSecond(int _element)
{
	if (!isFull())
	{
		headSecond--;
		*headSecond = _element;
	}
	else
	{
		// overFlow
	}
}

int DoubleStack::popFirst()
{
	if (!isEmptyFirst())
	{
		int retVal = *(headFirst-1);
		headFirst--;
		return retVal;
	}
	else
	{
		// underFlow
		return -1;
	}
}

int DoubleStack::popSecond()
{
	if (!isEmptySecond())
	{
		int retVal = *headSecond;
		headSecond++;
		return retVal;
	}
	else
	{
		// underFlow
		return -1;
	}
}

int DoubleStack::topFirst()
{
	if (isEmptyFirst())
	{
		return -1;
	}
	else
	{
		return *(headFirst - 1);
	}
}

int DoubleStack::topSecond()
{
	if (isEmptySecond())
	{
		return -1;
	}
	else
	{
		return *headSecond;
	}
}

// Task 03

Queue::Queue()
{
	queue = std::vector<int>(MAX01);
	front = queue.begin();
	back = queue.begin();
}

void Queue::pushBack(int _element) 
{
	if (length == MAX01)
	{
		// overFlow
	}
	else
	{
		if (back == queue.end())
			back = queue.begin();
		*back = _element;
		length++;
		back++;
	}
	
}

int Queue::popFront()
{
	if (isEmpty())
	{
		// underFlow
		return -1;
	}
	else
	{
		int retVal = *front;
		if (front == (queue.end() - 1))
			front = queue.begin();
		else
			front++;
		length--;
		return retVal;
	}
}

bool Queue::isEmpty()
{
	if (front == back && length == 0)
		return true;
	else
		return false;
}

// 10.1-4. Írjuk meg a Sorba és a Sorb ´ol m˝uveleteket úgy, hogy szerepeljen bennük az alulcsordulás
// és túlcsordulás vizsgálata.

// Task 05

Deque::Deque()
{
	deque = std::vector<int>(MAX01);
	front = deque.begin();
	back = deque.begin();
}

void Deque::pushFront(int _element) 
{
	if (length == MAX01)
	{
		// overFlow
	}
	else
	{
		if (front != deque.begin())
		{
			*(--front) = _element;
		}
		else
		{
			front = deque.end() - 1;
			*front = _element;
		}
		length++;
	}
}

void Deque::pushBack(int _element)
{
	if (length == MAX01)
	{
		// overFlow
	}
	else
	{
		if (back == deque.end())
			back = deque.begin();
		*back = _element;
		length++;
		back++;
	}
}

int Deque::popFront()
{
	if (isEmpty())
	{
		// underFlow
		return -1;
	}
	else
	{

		int retVal = *front;
		if (front == (deque.end() - 1))
			front = deque.begin();
		else
			front++;
		length--;
		return retVal;
	}
}

int Deque::popBack()
{
	if (isEmpty())
	{
		// underFlow
		return -1;
	}
	else
	{
		int retVal = -1;
		if (back != deque.begin())
		{
			retVal = *(back - 1);
			back--;
		}
		else
		{
			retVal = *(deque.end() - 1);
			back = (deque.end() - 1);
		}
		length--;
		return retVal;
	}
}

bool Deque::isEmpty()
{
	if (front == back && length == 0)
		return true;
	else
		return false;
}

// 10.1-6. Adjuk meg a sor megvalósítását két verem felhasználásával. Elemezzük a sor m˝uveleteinek
// a végrehajtási idejét.

