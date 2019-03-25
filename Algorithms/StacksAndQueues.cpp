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
		*back = _element;
		length++;
		back++;
		if (back == queue.end())
			back = queue.begin();
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

// Task 06

void QueueUsingStack::pushBack(int _element)
{
	if (length == MAX01)
	{
		// owerFlow
	}
	else
	{
		forward.push(_element);
		length++;
	}
}

int QueueUsingStack::popFront()
{
	if (isEmpty())
	{
		// underFlow
		return -1;
	}
	else
	{
		this->swap();
		int ret = backward.pop();
		this->swap();
		length--;
		return ret;
	}
}

bool QueueUsingStack::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

void QueueUsingStack::swap()
{
	if (forward.isEmpty())
	{
		while (!backward.isEmpty())
		{
			forward.push(backward.pop());
		}
	}
	else
	{
		while (!forward.isEmpty())
		{
			backward.push(forward.pop());
		}
	}
}

// Task 07

bool StackUsingQueue::isEmpty()
{
	if (first.isEmpty())
		return true;
	else
		return false;
}

void StackUsingQueue::push(int _element)
{
	first.pushBack(_element);
	if(stackTop() == _element)
		head = _element;
}

int StackUsingQueue::pop()
{
	if (first.isEmpty())
	{
		// under flow
		return -1;
	}
	else
	{
		return popStackTop();
	}
	return -1;
}

int StackUsingQueue::top()
{
	return head;
}

int StackUsingQueue::popStackTop()
{
	int accumulator = first.popFront();
	while (true)
	{	
		int tmp = first.popFront();
		if (tmp != -1)
		{
			second.pushBack(accumulator);
			accumulator = tmp;
		}
		else
			break;
	}
	int tmpHead = -1;
	int top = second.popFront();
	while (true)
	{
		if (top != -1)
		{
			first.pushBack(top);
			tmpHead = top;
			top = second.popFront();
		}
		else
		{
			head = tmpHead;
			break;
		}
	}
	return accumulator;
}

int StackUsingQueue::stackTop()
{
	int top = first.popFront();
	while (true)
	{
		int tmp = first.popFront();
		if (top != -1)
		{
			second.pushBack(top);
			top = tmp;
		}
		else
		{
			second.pushBack(tmp);
			break;
		}
	}
	int tmpHead = -1;
	int tmpTop = second.popFront();
	while (true)
	{
		if (tmpTop != -1)
		{
			first.pushBack(tmpTop);
			tmpHead = tmpTop;
			tmpTop = second.popFront();
		}
		else
		{
			head = tmpHead;
			break;
		}
	}
	return top;
}
