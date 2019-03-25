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

// 10.1-3. A 10.2. ábrán bemutatott modell felhasználásával szemléltessük a Sorba(S, 4),
// Sorba(S, 1), Sorba(S, 3), Sorb ´ol(S), Sorba(S, 8) és Sorb ´ol(S) m˝uveletek mindegyikének
// a végrehajtását, ha a sort a S[1 . . 6] tömbben tároljuk, és a sor kezdetben üres.

TEST_CASE("Queue 01")
{
	Queue q;
	REQUIRE(q.isEmpty() == true);
	q.pushBack(1);
	q.pushBack(2);
	q.pushBack(3);
	q.pushBack(4);
	REQUIRE(q.isEmpty() == false);
	q.pushBack(5);
	q.pushBack(6);
	q.pushBack(7);
}

TEST_CASE("Queue 02")
{
	Queue q;
	REQUIRE(q.isEmpty() == true);
	q.pushBack(1);
	q.pushBack(2);
	REQUIRE(q.popFront() == 1);
	REQUIRE(q.popFront() == 2);
	REQUIRE(q.isEmpty() == true);
	REQUIRE(q.popFront() == -1);
	REQUIRE(q.isEmpty() == true);
}

TEST_CASE("Queue 03")
{
	Queue q;
	q.pushBack(1);
	q.pushBack(2);
	q.pushBack(3);
	q.pushBack(4);
	q.pushBack(5);
	q.pushBack(6);
	REQUIRE(q.popFront() == 1);
	REQUIRE(q.popFront() == 2);
	REQUIRE(q.popFront() == 3);
	REQUIRE(q.popFront() == 4);
	q.pushBack(7);
	q.pushBack(8);
	q.pushBack(9);
	q.pushBack(10);
	REQUIRE(q.popFront() == 5);
	REQUIRE(q.popFront() == 6);
	REQUIRE(q.popFront() == 7);
	REQUIRE(q.popFront() == 8);
	q.pushBack(11);
	q.pushBack(12);
	q.pushBack(13);
	q.pushBack(14);
	REQUIRE(q.popFront() == 9);
	REQUIRE(q.popFront() == 10);
	REQUIRE(q.popFront() == 11);
	REQUIRE(q.popFront() == 12);
	q.pushBack(15);
	q.pushBack(16);
	q.pushBack(17);
	q.pushBack(18);
	REQUIRE(q.popFront() == 13);
	REQUIRE(q.popFront() == 14);
	REQUIRE(q.popFront() == 15);
	REQUIRE(q.popFront() == 16);
	q.pushBack(19);
	q.pushBack(20);
	q.pushBack(21);
	q.pushBack(22);
}

TEST_CASE("Queue 04")
{
	Queue q;

	REQUIRE(q.isEmpty() == true);
	REQUIRE(q.popFront() == -1);
	q.pushBack(1);
	q.pushBack(2);
	q.pushBack(3);
	q.pushBack(4);
	q.pushBack(5);
	q.pushBack(6);
	REQUIRE(q.isEmpty() == false);
	REQUIRE(q.popFront() == 1);
	REQUIRE(q.popFront() == 2);
	REQUIRE(q.popFront() == 3);
	REQUIRE(q.popFront() == 4);
	REQUIRE(q.popFront() == 5);
	REQUIRE(q.popFront() == 6);
	REQUIRE(q.isEmpty() == true);
	REQUIRE(q.popFront() == -1);
}

// 10.1-5. Amint láttuk, a veremnek csak az egyik végén lehet elemet beszúrni és törölni, a
// sornak pedig az egyik végén lehet elemet beszúrni és a másik végén lehet törölni. Ezzel
// szemben a kétvég˝u sor mindkét végén lehet elemet beszúrni is, és törölni is. Írjunk négy
// olyan O(1) idej˝u eljárást, amelyek megvalósítják a beszúrás és törlés m˝uveleteit egy tömbbel
// ábrázolt kétvég˝u sor mindkét végén.

TEST_CASE("Deque 01")
{
	Deque dq;
	REQUIRE(dq.isEmpty() == true);
	dq.pushBack(1);
	dq.pushFront(2);
	dq.pushBack(3);
	dq.pushFront(4);
	REQUIRE(dq.isEmpty() == false);
	REQUIRE(dq.popBack() == 3);
	REQUIRE(dq.popFront() == 4);
	REQUIRE(dq.popBack() == 1);
	REQUIRE(dq.popFront() == 2);
	REQUIRE(dq.isEmpty() == true);
}

TEST_CASE("Deque 02")
{
	Deque dq;
	REQUIRE(dq.isEmpty() == true);
	REQUIRE(dq.popBack() == -1);
	REQUIRE(dq.popFront() == -1);
	dq.pushBack(1);
	REQUIRE(dq.isEmpty() == false);
	REQUIRE(dq.popFront() == 1);
	REQUIRE(dq.isEmpty() == true);
	dq.pushFront(1);
	REQUIRE(dq.isEmpty() == false);
	REQUIRE(dq.popBack() == 1);
}

TEST_CASE("Deque 03")
{
	Deque dq;
	REQUIRE(dq.isEmpty() == true);
	dq.pushBack(1);
	dq.pushBack(2);
	dq.pushBack(3);
	dq.pushBack(4);
	dq.pushBack(5);
	dq.pushBack(6);
	REQUIRE(dq.popFront() == 1);
	REQUIRE(dq.popFront() == 2);
	REQUIRE(dq.popFront() == 3);
	REQUIRE(dq.popFront() == 4);
	dq.pushBack(7);
	dq.pushBack(8);
	dq.pushBack(9);
	dq.pushBack(10);
	REQUIRE(dq.popFront() == 5);
	REQUIRE(dq.popFront() == 6);
	REQUIRE(dq.popFront() == 7);
	REQUIRE(dq.popFront() == 8);
	dq.pushBack(11);
	dq.pushBack(12);
	dq.pushBack(13);
	dq.pushBack(14);
	REQUIRE(dq.popFront() == 9);
	REQUIRE(dq.popFront() == 10);
	REQUIRE(dq.popFront() == 11);
	REQUIRE(dq.popFront() == 12);
	REQUIRE(dq.popFront() == 13);
	REQUIRE(dq.popFront() == 14);
	REQUIRE(dq.isEmpty() == true);
	dq.pushFront(13);
	dq.pushFront(14);
	dq.pushFront(15);
	dq.pushFront(16);
	dq.pushFront(17);
	dq.pushFront(18);
	REQUIRE(dq.popBack() == 13);
	REQUIRE(dq.popBack() == 14);
	REQUIRE(dq.popBack() == 15);
	REQUIRE(dq.popBack() == 16);
	dq.pushFront(19);
	dq.pushFront(20);
	dq.pushFront(21);
	dq.pushFront(22);
	REQUIRE(dq.popBack() == 17);
	REQUIRE(dq.popBack() == 18);
	REQUIRE(dq.popBack() == 19);
	REQUIRE(dq.popBack() == 20);
	dq.pushFront(23);
	dq.pushFront(24);
	dq.pushFront(25);
	dq.pushFront(26);
	REQUIRE(dq.popBack() == 21);
	REQUIRE(dq.popBack() == 22);
	REQUIRE(dq.popBack() == 23);
	REQUIRE(dq.popBack() == 24);
	dq.pushFront(27);
	dq.pushFront(28);
	dq.pushFront(29);
	dq.pushFront(30);
	REQUIRE(dq.popBack() == 25);
	REQUIRE(dq.popBack() == 26);
	REQUIRE(dq.popBack() == 27);
	REQUIRE(dq.popBack() == 28);
}

// 10.1-6. Adjuk meg a sor megvalósítását két verem felhasználásával. Elemezzük a sor m˝uveleteinek
// a végrehajtási idejét.

TEST_CASE("QueueUsingStack 01")
{
	QueueUsingStack qs;
	REQUIRE(qs.isEmpty() == true);
	qs.pushBack(1);
	qs.pushBack(2);
	qs.pushBack(3);
	qs.pushBack(4);
	REQUIRE(qs.isEmpty() == false);
	qs.pushBack(5);
	qs.pushBack(6);
	qs.pushBack(7);
}

TEST_CASE("QueueUsingStack 02")
{
	QueueUsingStack qs;
	REQUIRE(qs.isEmpty() == true);
	qs.pushBack(1);
	qs.pushBack(2);
	REQUIRE(qs.popFront() == 1);
	REQUIRE(qs.popFront() == 2);
	REQUIRE(qs.isEmpty() == true);
	REQUIRE(qs.popFront() == -1);
	REQUIRE(qs.isEmpty() == true);
}

TEST_CASE("QueueUsingStack 03")
{
	QueueUsingStack qs;
	qs.pushBack(1);
	qs.pushBack(2);
	qs.pushBack(3);
	qs.pushBack(4);
	qs.pushBack(5);
	qs.pushBack(6);
	REQUIRE(qs.popFront() == 1);
	REQUIRE(qs.popFront() == 2);
	REQUIRE(qs.popFront() == 3);
	REQUIRE(qs.popFront() == 4);
	qs.pushBack(7);
	qs.pushBack(8);
	qs.pushBack(9);
	qs.pushBack(10);
	REQUIRE(qs.popFront() == 5);
	REQUIRE(qs.popFront() == 6);
	REQUIRE(qs.popFront() == 7);
	REQUIRE(qs.popFront() == 8);
	qs.pushBack(11);
	qs.pushBack(12);
	qs.pushBack(13);
	qs.pushBack(14);
	REQUIRE(qs.popFront() == 9);
	REQUIRE(qs.popFront() == 10);
	REQUIRE(qs.popFront() == 11);
	REQUIRE(qs.popFront() == 12);
	qs.pushBack(15);
	qs.pushBack(16);
	qs.pushBack(17);
	qs.pushBack(18);
	REQUIRE(qs.popFront() == 13);
	REQUIRE(qs.popFront() == 14);
	REQUIRE(qs.popFront() == 15);
	REQUIRE(qs.popFront() == 16);
	qs.pushBack(19);
	qs.pushBack(20);
	qs.pushBack(21);
	qs.pushBack(22);
}

TEST_CASE("QueueUsingStack 04")
{
	QueueUsingStack qs;

	REQUIRE(qs.isEmpty() == true);
	REQUIRE(qs.popFront() == -1);
	qs.pushBack(1);
	qs.pushBack(2);
	qs.pushBack(3);
	qs.pushBack(4);
	qs.pushBack(5);
	qs.pushBack(6);
	REQUIRE(qs.isEmpty() == false);
	REQUIRE(qs.popFront() == 1);
	REQUIRE(qs.popFront() == 2);
	REQUIRE(qs.popFront() == 3);
	REQUIRE(qs.popFront() == 4);
	REQUIRE(qs.popFront() == 5);
	REQUIRE(qs.popFront() == 6);
	REQUIRE(qs.isEmpty() == true);
	REQUIRE(qs.popFront() == -1);
}

// 10.1-7. Adjuk meg a verem megvalósítását két sor felhasználásával. Elemezzük a verem
// m˝uveleteinek végrehajtási idejét.

TEST_CASE("StackUsingQueue 01")
{
	StackUsingQueue sq;
	REQUIRE(sq.isEmpty() == true);
	sq.push(4);
	sq.push(1);
	sq.push(3);
	REQUIRE(sq.top() == 3);
	REQUIRE(sq.pop() == 3);
	REQUIRE(sq.top() == 1);
	sq.push(8);
	REQUIRE(sq.pop() == 8);
	REQUIRE(sq.isEmpty() == false);
	sq.push(6);
	sq.push(9);
	sq.push(15);
	REQUIRE(sq.top() == 15);
	REQUIRE(sq.isEmpty() == false);
	sq.push(1);
	sq.push(10);
	REQUIRE(sq.top() == 1);
}

TEST_CASE("StackUsingQueue 02")
{
	StackUsingQueue sq;
	REQUIRE(sq.pop() == -1);
	REQUIRE(sq.top() == -1);
	REQUIRE(sq.isEmpty() == true);

	sq.push(1);
	REQUIRE(sq.top() == 1);
	REQUIRE(sq.isEmpty() == false);

	REQUIRE(sq.pop() == 1);
	REQUIRE(sq.top() == -1);
	REQUIRE(sq.isEmpty() == true);
}

TEST_CASE("StackUsingQueue 03")
{
	StackUsingQueue sq;
	sq.push(1);
	sq.push(2);
	sq.push(3);
	sq.push(4);
	sq.push(5);
	sq.push(6);
	REQUIRE(sq.top() == 6);
	sq.push(7);
	sq.push(8);
	sq.push(9);
	REQUIRE(sq.top() == 6);
	REQUIRE(sq.pop() == 6);
	sq.push(7);
	REQUIRE(sq.top() == 7);
}