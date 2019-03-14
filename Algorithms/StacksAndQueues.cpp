#include "StacksAndQueues.h"

// 10.1-1 A ábrán bemutatott modell felhasználásával szemléltessük a Verembe(V,4),
// Verembe(V, 1), Verembe(V, 3), Veremb ˝ol(V), Verembe(V, 8) és Veremb˝ol(V) m˝uveletek
// mindegyikének a végrehajtását, ha a vermet a V[1 . . 6] tömbben tároljuk, és a verem kezdetben üres.

bool Stack::isEmpty()
{
	if (*head == 0)
		return true;
	else
		return false;
}

void Stack::push(int _element)
{
	if (*head < MAX01)
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
		int _localHead = *head;
		head--; 
		return _localHead;
	}
}

// 10.1-2 Hogyan valósítható meg két verem egyetlen A[1 . . n] tömbben úgy, hogy egyik verem
// sem csordul túl addig, amíg együttes elemszámuk nem haladja meg az n - et ? A Verembe
// és Veremb˝ol m˝uveletek végrehajtási ideje maradjon O(1).

bool DoubleStack::isEmptyFirst()
{
	if (*headFirst == 0)
		return true;
	else
		return false;
}

bool DoubleStack::isEmptySecond()
{
	if (*headSecond == MAX02)
		return true;
	else
		return false;
}

bool DoubleStack::isFull()
{
	if (*headFirst == *headSecond)
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
		int retVal = *headFirst;
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

