#include <iostream>

#include "StacksAndQueues.h"


int main(int argc, char* argv[]) {

	int stack[MAX01];

	std::cout << isEmpty() << std::endl;
	push(stack, 4);
	push(stack, 1);
	push(stack, 3);
	pop(stack);
	push(stack, 8);
	pop(stack);
	std::cout << isEmpty() << std::endl;
	push(stack, 6);
	push(stack, 9);
	push(stack, 15);
	std::cout << isEmpty() << std::endl;
	push(stack, 1);
	push(stack, 10);

	return 0;
}