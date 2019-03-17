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
	if (isFull())
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

bool Queue::isFull()
{
	if (length == MAX01)
		return true;
	else
		return false;
}

// 10.1-4. Írjuk meg a Sorba és a Sorb ´ol m˝uveleteket úgy, hogy szerepeljen bennük az alulcsordulás
// és túlcsordulás vizsgálata.

// 10.1-5. Amint láttuk, a veremnek csak az egyik végén lehet elemet beszúrni és törölni, a
// sornak pedig az egyik végén lehet elemet beszúrni és a másik végén lehet törölni. Ezzel
// szemben a kétvég˝u sor mindkét végén lehet elemet beszúrni is, és törölni is. Írjunk négy
// olyan O(1) idej˝u eljárást, amelyek megvalósítják a beszúrás és törlés m˝uveleteit egy tömbbel
// ábrázolt kétvég˝u sor mindkét végén.

int _headDeQueue = 0;
int _tailDeQueue = 0;
int _sizeDeQueue = 0;

void pushDeqFront(int _deq[], int _element) 
{
	if (_sizeDeQueue == MAX01)
	{
		// overFlow
	}
	else
	{
		_deq[_headDeQueue] = _element;
		if (_sizeDeQueue == 0 && _tailDeQueue == 0)
		{
			_headDeQueue = MAX01 - 1;
			_tailDeQueue++;
		}
		else if (_headDeQueue == 0)
			_headDeQueue = MAX01 - 1;
		else
			_headDeQueue--;
		_sizeDeQueue++;
	}
}

void pushDeqBack(int _deq[], int _element)
{
	if (_sizeDeQueue == MAX01)
	{
		// overFlow
	}
	else
	{
		_deq[_tailDeQueue] = _element;
		if (_sizeDeQueue == 0 && _headDeQueue == 0)
		{
			_tailDeQueue++;
			_headDeQueue = MAX01 - 1;
		}
		else if (_tailDeQueue == MAX01 - 1)
			_tailDeQueue = 0;
		else
			_tailDeQueue++;
		_sizeDeQueue++;
	}
}

int popDeqFront(int _deq[])
{
	if (_sizeDeQueue == 0)
	{
		// underFlow
		return -1;
	}
	else
	{
		int retVal = _deq[_headDeQueue];
		if (_headDeQueue == MAX01 - 1)
			_headDeQueue = 0;
		else
			_headDeQueue++;
		_sizeDeQueue--;
		return retVal;
	}
}

int popDeqBack(int _deq[])
{
	if (_sizeDeQueue == 0)
	{
		// underFlow
		return -1;
	}
	else
	{
		int retVal = _deq[_tailDeQueue];
		if (_tailDeQueue == 0)
			_tailDeQueue = MAX01 - 1;
		else
			_tailDeQueue--;
		_sizeDeQueue--;
		return retVal;
	}
}

// 10.1-6. Adjuk meg a sor megvalósítását két verem felhasználásával. Elemezzük a sor m˝uveleteinek
// a végrehajtási idejét.

