#include "LinkedLists.h"

#include "catch.hpp"

// 10.2-1. Megvalósítható-e a dinamikus halmazokra értelmezett Besz ´ur m˝uvelet egyszeresen
// láncolt listákra O(1) id ˝oben ? Mi a helyzet a T¨or¨ol m˝uvelettel ?

TEST_CASE("DoublyLinkedList add")
{
	REQUIRE(DoublyLinkedList::counter == 0);
	DoublyLinkedList ll;
	REQUIRE(ll.head == nullptr);
	REQUIRE(ll.isEmpty() == true);
	ll.add(0);
	REQUIRE(ll.isEmpty() == false);
	REQUIRE(ll.head->getData() == 0);
	REQUIRE(ll.head->next == nullptr);
	REQUIRE(ll.head->prev == nullptr);
	ll.add(1);
	ll.add(2);
	ll.add(3);
	REQUIRE(ll.isEmpty() == false);
	REQUIRE(ll.head->getData() == 3);
	Node* tmp = ll.head;
	tmp = tmp->next;
	REQUIRE(tmp->getData() == 2);
	tmp = tmp->next;
	REQUIRE(tmp->getData() == 1);
	tmp = tmp->next;
	REQUIRE(tmp->getData() == 0);
}

TEST_CASE("DoublyLinkedList remove")
{
	REQUIRE(DoublyLinkedList::counter == 0);
	DoublyLinkedList ll;
	ll.add(0);
	REQUIRE(ll.isEmpty() == false);
	ll.remove(ll.search(0));
	REQUIRE(ll.isEmpty() == true);
	ll.add(0);
	REQUIRE(ll.isEmpty() == false);
	ll.add(1);
	ll.remove(ll.search(1));
	REQUIRE(ll.isEmpty() == false);
	ll.add(1);
	ll.add(2);
	ll.add(3);
	ll.add(4);
	ll.remove(ll.search(3));
	ll.remove(ll.search(2));
	ll.remove(ll.search(1));
	ll.remove(ll.search(4));
	ll.remove(ll.search(0));
	REQUIRE(ll.isEmpty() == true);
}

TEST_CASE("DoublyLinkedList search")
{
	REQUIRE(DoublyLinkedList::counter == 0);
	DoublyLinkedList ll;
	REQUIRE(ll.search(0) == nullptr);
	ll.add(0);
	REQUIRE(ll.search(0)->getData() == 0);
	REQUIRE(ll.search(1) == nullptr);
	ll.add(1);
	REQUIRE(ll.search(1)->getData() == 1);
}

// 10.2-2. Valósítsuk meg a vermet egyszer˝u láncolt listával. A Verembe és Veremb ˝ol m˝uveletek
// végrehajtási ideje maradjon O(1).

TEST_CASE("StackUsingLinkedList 01")
{
	StackUsingLinkedList s;
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

TEST_CASE("StackUsingLinkedList 02")
{
	StackUsingLinkedList s;
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

TEST_CASE("StackUsingLinkedList 03")
{
	StackUsingLinkedList s;
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

// 10.2 - 3. Valósítsuk meg a sort egyszer˝u láncolt listával.A Sorba és Sorb ´ol m˝uveletek végrehajtási
// ideje maradjon O(1).

TEST_CASE("QueueUsingLinedList 01")
{
	QueueUsingLinedList q;
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

TEST_CASE("QueueUsingLinedList 02")
{
	QueueUsingLinedList q;
	REQUIRE(q.isEmpty() == true);
	q.pushBack(1);
	q.pushBack(2);
	REQUIRE(q.popFront() == 1);
	REQUIRE(q.popFront() == 2);
	REQUIRE(q.isEmpty() == true);
	REQUIRE(q.popFront() == -1);
	REQUIRE(q.isEmpty() == true);
}

TEST_CASE("QueueUsingLinedList 03")
{
	QueueUsingLinedList q;
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

TEST_CASE("QueueUsingLinedList 04")
{
	QueueUsingLinedList q;

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


// 10.2 - 4. Amint láttuk, a List´aban - keres eljárás az iteráció minden lépésében két vizsgálatot
// végez : ellen ˝orzi az x  nil[L], valamint a kulcs[x]  k feltétel teljesülését.Adjuk meg,
//	hogyan lehetne az x  nil[L] vizsgálatot kiküszöbölni a ciklusból.

