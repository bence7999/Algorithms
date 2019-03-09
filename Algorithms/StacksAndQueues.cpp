#include "StacksAndQueues.h"

// 10.1-1 A ábrán bemutatott modell felhasználásával szemléltessük a Verembe(V,4),
// Verembe(V, 1), Verembe(V, 3), Veremb ˝ol(V), Verembe(V, 8) és Veremb˝ol(V) m˝uveletek
// mindegyikének a végrehajtását, ha a vermet a V[1 . . 6] tömbben tároljuk, és a verem kezdetben üres.

int _head01 = 0;

bool isEmpty()
{
	if (_head01 == 0)
		return true;
	else
		return false;
}

void push(int _stack[], int _element)
{
	if (_head01 < 6)
	{
		_stack[_head01] = _element;
		++_head01;
	}
}

int pop(int _stack[])
{
	if (isEmpty())
		return -1;
	else
	{
		int _head = _stack[_head01];
		--_head01;
		return _head;
	}
}


