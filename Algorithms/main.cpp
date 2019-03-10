#include <iostream>

#include "StacksAndQueues.h"


int main(int argc, char* argv[]) {

	int dequeue[MAX01];

	std::cout << popDeqFront(dequeue) << std::endl;
	std::cout << popDeqBack(dequeue) << std::endl;

	pushDeqBack(dequeue, 1);
	pushDeqFront(dequeue, 2);
	pushDeqBack(dequeue, 3);
	pushDeqFront(dequeue, 4);
	pushDeqBack(dequeue, 5);
	pushDeqFront(dequeue, 6);

	std::cout << popDeqFront(dequeue) << std::endl;
	std::cout << popDeqBack(dequeue) << std::endl;

	pushDeqBack(dequeue, 10);
	pushDeqBack(dequeue, 11);
	pushDeqBack(dequeue, 12);

	std::cout << popDeqBack(dequeue) << std::endl;
	std::cout << popDeqBack(dequeue) << std::endl;

	pushDeqFront(dequeue, 20);
	pushDeqFront(dequeue, 21);
	pushDeqFront(dequeue, 22);

	return 0;
}