#include "LinkedLists.h"

// Task 01

int LinkedList::counter = 0;

LinkedList::~LinkedList()
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
	LinkedList::counter++;
}

Node::~Node()
{
	LinkedList::counter--;
}

int Node::getData()
{
	return data;
}

void LinkedList::add(int _data)
{
	Node* node = new Node(_data);
	if (head == nullptr)
		head = node;
	else
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
}

int LinkedList::remove(int _data)
{
	if (head == nullptr)
		return -1;

	if (head->getData() == _data)
		return removeFront(_data);
	else
	{
		Node* cancelland = search(_data);
		if (cancelland->next == nullptr) {
			return removeBack(_data);
		}
		else
		{
			Node* tmp = head;
			while (tmp->next != cancelland)
			{
				tmp = tmp->next;
			}
			tmp->next = cancelland->next;
			int ret = cancelland->getData();
			cancelland->~Node();
			return ret;
		}
	}
	return -1;
}

int LinkedList::removeFront(int _data)
{
	Node* tmp = head;
	if (tmp->next == nullptr)
	{
		head = nullptr;
		tmp->~Node();
		return tmp->getData();
	}
	head = head->next;
	int ret = tmp->getData();
	tmp->~Node();
	return ret;
}

int LinkedList::removeBack(int _data)
{
	Node* tmp = head;
	if (tmp->next == nullptr)
	{
		head = nullptr;
		int ret = tmp->getData();
		tmp->~Node();
		return ret;
	}
	else
	{
		while (tmp->next->next != nullptr)
		{
			tmp = tmp->next;
		}
		Node* cancellable = tmp->next;
		tmp->next = nullptr;
		int ret = cancellable->getData();
		cancellable->~Node();
		return ret;
	}

}
 
Node* LinkedList::search(int _data)
{
	Node* tmp = head;
	while (tmp->getData() != _data)
	{
		tmp = tmp->next;
	}
	return tmp;
}

bool LinkedList::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

// Task 02

/*bool StackUsingLinkedList::isEmpty()
{

}

void StackUsingLinkedList::push(int _element)
{

}

int StackUsingLinkedList::pop()
{

}

int StackUsingLinkedList::top()
{

}*/