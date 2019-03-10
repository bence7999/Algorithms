#include <iostream>

#include "StacksAndQueues.h"


int main(int argc, char* argv[]) {

	int queue[MAX01];

	pushBack(queue, 1);
	pushBack(queue, 2);
	pushBack(queue, 3);
	popFront(queue);
	pushBack(queue, 4);
	pushBack(queue, 5);
	pushBack(queue, 6);
	popFront(queue);
	pushBack(queue, 7);
	pushBack(queue, 8);
	pushBack(queue, 9);
	popFront(queue);
	pushBack(queue, 10);
	pushBack(queue, 11);
	pushBack(queue, 12);

	return 0;
}