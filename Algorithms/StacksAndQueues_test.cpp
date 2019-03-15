#include "StacksAndQueues.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// 10.1-1 A ábrán bemutatott modell felhasználásával szemléltessük a Verembe(V,4),
// Verembe(V, 1), Verembe(V, 3), Veremb ˝ol(V), Verembe(V, 8) és Veremb˝ol(V) m˝uveletek
// mindegyikének a végrehajtását, ha a vermet a V[1 . . 6] tömbben tároljuk, és a verem kezdetben üres.

TEST_CASE("Stack 01")
{
	Stack s;
	REQUIRE(s.isEmpty() == true);
	s.push(4);
	s.push(1);
	s.push(3);
	REQUIRE(s.top() == 3);
	REQUIRE(s.pop() == 3);
	REQUIRE(s.top() == 1);
	s.push(8);
	REQUIRE(s.pop() == 8);
	REQUIRE(s.isEmpty() == false);
	s.push(6);
	s.push(9);
	s.push(15);
	REQUIRE(s.top() == 15);
	REQUIRE(s.isEmpty() == false);
	s.push(1);
	s.push(10);
	REQUIRE(s.top() == 1);
}

TEST_CASE("Stack 02")
{
	Stack s;
	REQUIRE(s.pop() == -1);
	REQUIRE(s.top() == -1);
	REQUIRE(s.isEmpty() == true);

	s.push(1);
	REQUIRE(s.top() == 1);
	REQUIRE(s.isEmpty() == false);

	REQUIRE(s.pop() == 1);
	REQUIRE(s.top() == -1);
	REQUIRE(s.isEmpty() == true);
}

TEST_CASE("Stack 03")
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	REQUIRE(s.top() == 6);
	s.push(7);
	s.push(8);
	s.push(9);
	REQUIRE(s.top() == 6);
	REQUIRE(s.pop() == 6);
	s.push(7);
	REQUIRE(s.top() == 7);
}

// 10.1-2 Hogyan valósítható meg két verem egyetlen A[1 . . n] tömbben úgy, hogy egyik verem
// sem csordul túl addig, amíg együttes elemszámuk nem haladja meg az n - et ? A Verembe
// és Veremb˝ol m˝uveletek végrehajtási ideje maradjon O(1).

TEST_CASE("DoubleStack 01")
{
	DoubleStack ds;
	REQUIRE(ds.isFull() == false);
	REQUIRE(ds.isEmptyFirst() == true);
	REQUIRE(ds.isEmptySecond() == true);
	ds.pushFirst(1);
	ds.pushFirst(3);
	ds.pushFirst(5);
	ds.pushFirst(7);
	ds.pushSecond(2);
	ds.pushSecond(4);
	ds.pushSecond(6);
	ds.pushSecond(8);
	REQUIRE(ds.isFull() == false);
	REQUIRE(ds.isEmptyFirst() == false);
	REQUIRE(ds.isEmptySecond() == false);
	REQUIRE(ds.topFirst() == 7);
	REQUIRE(ds.topSecond() == 8);
	REQUIRE(ds.popFirst() == 7);
	REQUIRE(ds.popSecond() == 8);
	REQUIRE(ds.topFirst() == 5);
	REQUIRE(ds.topSecond() == 6);
}

TEST_CASE("DoubleStack 02")
{
	DoubleStack ds;
	REQUIRE(ds.isEmptyFirst() == true);
	REQUIRE(ds.isEmptySecond() == true);
	ds.pushFirst(1);
	ds.pushSecond(2);
	REQUIRE(ds.isEmptyFirst() == false);
	REQUIRE(ds.isEmptySecond() == false);
	REQUIRE(ds.popFirst() == 1);
	REQUIRE(ds.popSecond() == 2);
	REQUIRE(ds.isEmptyFirst() == true);
	REQUIRE(ds.isEmptySecond() == true);
	REQUIRE(ds.popFirst() == -1);
	REQUIRE(ds.popSecond() == -1);
	REQUIRE(ds.isEmptyFirst() == true);
	REQUIRE(ds.isEmptySecond() == true);
}

TEST_CASE("DoubleStack 03")
{
	DoubleStack ds;
	ds.pushFirst(1);
	ds.pushFirst(2);
	ds.pushFirst(3);
	ds.pushFirst(4);
	ds.pushFirst(5);
	ds.pushFirst(6);
	ds.pushFirst(7);
	ds.pushFirst(8);
	ds.pushFirst(9);
	ds.pushSecond(20);
	ds.pushSecond(19);
	ds.pushSecond(18);
	ds.pushSecond(17);
	ds.pushSecond(16);
	ds.pushSecond(15);
	ds.pushSecond(14);
	ds.pushSecond(13);
	ds.pushSecond(12);
	REQUIRE(ds.topFirst() == 9);
	REQUIRE(ds.topSecond() == 12);
	REQUIRE(ds.isFull() == false);
	ds.pushFirst(10);
	ds.pushSecond(11);
	REQUIRE(ds.topFirst() == 10);
	REQUIRE(ds.topSecond() == 11);
	REQUIRE(ds.isFull() == true);
}

TEST_CASE("DoubleStack 04")
{
	DoubleStack ds;
	REQUIRE(ds.topFirst() == -1);
	REQUIRE(ds.topSecond() == -1);
	REQUIRE(ds.popFirst() == -1);
	REQUIRE(ds.popSecond() == -1);
	REQUIRE(ds.isEmptyFirst() == true);
	REQUIRE(ds.isEmptySecond() == true);
	
	for (int i = 1; i < 20; i++)
	{
		ds.pushFirst(i);
	}

	REQUIRE(ds.isFull() == false);
	REQUIRE(ds.isEmptyFirst() == false);
	REQUIRE(ds.isEmptySecond() == true);
	REQUIRE(ds.topFirst() == 19);
	REQUIRE(ds.topSecond() == -1);
	
	ds.pushFirst(20);

	REQUIRE(ds.isFull() == true);
	REQUIRE(ds.isEmptyFirst() == false);
	REQUIRE(ds.isEmptySecond() == true);
	REQUIRE(ds.topFirst() == 20);
	REQUIRE(ds.topSecond() == -1);

	ds.pushFirst(21);
	REQUIRE(ds.topFirst() == 20);

	REQUIRE(ds.popFirst() == 20);
	REQUIRE(ds.isFull() == false);

	ds.pushSecond(20);
	REQUIRE(ds.isFull() == true);

	for (int i = 19; i > 1; i--)
	{
		REQUIRE(ds.popFirst() == i);
		ds.pushSecond(i);
	}

	REQUIRE(ds.isFull() == true);
	REQUIRE(ds.isEmptyFirst() == false);
	REQUIRE(ds.isEmptySecond() == false);

	REQUIRE(ds.popFirst() == 1);
	ds.pushSecond(1);
	REQUIRE(ds.isFull() == true);
	REQUIRE(ds.isEmptyFirst() == true);
	REQUIRE(ds.isEmptySecond() == false);
	REQUIRE(ds.topSecond() == 1);

	REQUIRE(ds.popFirst() == -1);
	ds.pushSecond(0);
	REQUIRE(ds.topSecond() == 1);
	REQUIRE(ds.isFull() == true);
}