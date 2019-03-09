#include <iostream>

#include "StacksAndQueues.h"


int main(int argc, char* argv[]) {

	int stack[MAX02];

	std::cout << isFull() << std::endl;
	std::cout << isEmptyFirst() << std::endl;
	std::cout << isEmptySecond() << std::endl;

	pushFirst(stack, 1);
	pushFirst(stack, 3);
	pushFirst(stack, 5);
	pushFirst(stack, 7);
	pushSecond(stack, 2);
	pushSecond(stack, 4);
	pushSecond(stack, 6);
	popSecond(stack);
	popFirst(stack);

	std::cout << isFull() << std::endl;
	std::cout << isEmptyFirst() << std::endl;
	std::cout << isEmptySecond() << std::endl;

	pushSecond(stack, 10);
	pushSecond(stack, 12);
	pushSecond(stack, 14);
	pushSecond(stack, 16);
	pushFirst(stack, 11);
	pushFirst(stack, 13);
	pushFirst(stack, 15);

	std::cout << isFull() << std::endl;
	std::cout << isEmptyFirst() << std::endl;
	std::cout << isEmptySecond() << std::endl;

	pushFirst(stack, 21);
	pushFirst(stack, 23);
	pushSecond(stack, 20);
	pushSecond(stack, 22);
	pushFirst(stack, 25);
	pushFirst(stack, 27);
	pushSecond(stack, 24);
	pushSecond(stack, 26);

	std::cout << isFull() << std::endl;
	std::cout << isEmptyFirst() << std::endl;
	std::cout << isEmptySecond() << std::endl;

	return 0;
}