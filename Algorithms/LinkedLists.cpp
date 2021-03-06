#include "LinkedLists.h"

#define MAX01 6

// Task 01

int DoublyLinkedList::counter = 0;

DoublyLinkedList::~DoublyLinkedList()
{
	Node* tmp = head;
	if (tmp != nullptr)
	{
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
			head->~Node();
			head = tmp;
		}
		tmp->~Node();
	}
}

Node::Node(int _data)
	: data(_data) 
{
	next = nullptr;
	DoublyLinkedList::counter++;
}

Node::~Node()
{
	DoublyLinkedList::counter--;
}

int Node::getData()
{
	return data;
}

void DoublyLinkedList::add(int _data)
{
	Node* node = new Node(_data);
	node->next = head;
	if (head != nullptr)
		head->prev = node;
	head = node;
}

void DoublyLinkedList::remove(Node* node)
{
	if (node->prev != nullptr)
	{
		node->prev->next = node->next;
	}
	else
	{
		head = node->next;
	}

	if (node->next != nullptr)
	{
		node->next->prev = node->prev;
	}

	node->~Node();
}

Node* DoublyLinkedList::search(int _data)
{
	Node* tmp = head;
	while (tmp != nullptr && tmp->getData() != _data)
	{
		tmp = tmp->next;
	}
	return tmp;
}

bool DoublyLinkedList::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

// Task 02

bool StackUsingLinkedList::isEmpty()
{
	if (ll.isEmpty())
		return true;
	else
		return false;
}

void StackUsingLinkedList::push(int _element)
{
	if (length < MAX01)
	{
		ll.add(_element);
		length++;
	}
	else
	{
		// overflow
	}
}

int StackUsingLinkedList::pop()
{
	if (! ll.isEmpty())
	{
		length--;
		int top = this->top();
		ll.remove(ll.head);
		return top;
	}
	else
	{
		// underflow
		return -1;
	}
}

int StackUsingLinkedList::top()
{
	if (!ll.isEmpty())
	{
		return ll.head->getData();
	}
	else
		return -1; // stack is empty
}

// Task 03

void QueueUsingLinedList::pushBack(int _data)
{
	ll.add(_data);
	if (tail == nullptr)
		tail = ll.head;
}

int QueueUsingLinedList::popFront()
{
	if (!isEmpty())
	{
		Node* node = tail;
		if (tail->prev != nullptr)
		{
			tail = node->prev;
			tail->next = nullptr;
		}
		else {
			tail = nullptr;
		}
		int top = node->getData();
		ll.remove(node);
		return top;
	}
	return -1;
}

bool QueueUsingLinedList::isEmpty()
{
	if (ll.head == nullptr)
		return true;
	else
		return false;
}

// Task 04

// Task 05

CyclicLinkedList::~CyclicLinkedList()
{

}

void CyclicLinkedList::Add(int _data)
{
	Node* node = new Node(_data);
	if (IsEmpty())
	{
		last = node;
		node->next = node;
	}
	else
	{
		node->next = last->next;
		last->next = node;
		last = node;
	}
}

void CyclicLinkedList::Remove(Node* _node)
{
	if (_node->next == _node)
	{
		last = nullptr;
		_node->~Node();
	}
	else if(_node == last)
	{
		Node* node = _node;
		while (node->next != _node)
		{
			node = node->next;
		}
		node->next = last->next;
		last->~Node();
		last = node;
	}
	else
	{
		Node* node = _node;
		while (node->next != _node)
		{
			node = node->next;
		}
		node->next = _node->next;
		_node->~Node();
	}
}

Node* CyclicLinkedList::Search(int _data)
{
	if (last == nullptr) return nullptr;
	Node* node = last;
	while (node->next != last && node->getData() != _data)
	{
		node = node->next;
	}

	if (node->getData() == _data)
		return node;
	else
		return nullptr;
}

bool CyclicLinkedList::IsEmpty()
{
	if (last == nullptr)
		return true;
	else
		return false;
}

Node* CyclicLinkedList::GetLast()
{
	return last;
}