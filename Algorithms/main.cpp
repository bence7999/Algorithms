#include <iostream>

#include "StacksAndQueues.h"


int main(int argc, char* argv[]) {

	int queue[MAX01];

	popFront(queue);
	popFront(queue);
	pushBack(queue, 1);
	pushBack(queue, 2);
	pushBack(queue, 3);
	pushBack(queue, 4);
	pushBack(queue, 5);
	pushBack(queue, 6);
	pushBack(queue, 7);
	pushBack(queue, 8);

	return 0;
}