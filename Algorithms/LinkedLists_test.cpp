#include "LinkedLists.h"

#include "catch.hpp"

// 10.2-1. Megvalósítható-e a dinamikus halmazokra értelmezett Besz ´ur m˝uvelet egyszeresen
// láncolt listákra O(1) id ˝oben ? Mi a helyzet a T¨or¨ol m˝uvelettel ?

TEST_CASE("LinketList add")
{
	REQUIRE(LinkedList::counter == 0);
	LinkedList ll;
	REQUIRE(ll.isEmpty() == true);
	ll.add(0);
	REQUIRE(ll.isEmpty() == false);
	REQUIRE(ll.head->getData() == 0);
	ll.add(1);
	ll.add(2);
	ll.add(3);
	REQUIRE(ll.isEmpty() == false);
	REQUIRE(ll.head->getData() == 0);
	Node* tmp = ll.head;
	tmp = tmp->next;
	REQUIRE(tmp->getData() == 1);
	tmp = tmp->next;
	REQUIRE(tmp->getData() == 2);
	tmp = tmp->next;
	REQUIRE(tmp->getData() == 3);
}

TEST_CASE("LinkedList remove")
{
	REQUIRE(LinkedList::counter == 0);
	LinkedList ll;
	ll.add(0);
	REQUIRE(ll.isEmpty() == false);
	REQUIRE(ll.remove(0) == 0);
	REQUIRE(ll.isEmpty() == true);
	ll.add(0);
	REQUIRE(ll.isEmpty() == false);
	ll.add(1);
	REQUIRE(ll.remove(1) == 1);
	REQUIRE(ll.isEmpty() == false);
	ll.add(1);
	ll.add(2);
	ll.add(3);
	ll.add(4);
	REQUIRE(ll.remove(3) == 3);
	REQUIRE(ll.remove(2) == 2);
	REQUIRE(ll.remove(1) == 1);
	REQUIRE(ll.remove(4) == 4);
	REQUIRE(ll.remove(0) == 0);
	REQUIRE(ll.isEmpty() == true);
}

// 10.2-2. Valósítsuk meg a vermet egyszer˝u láncolt listával. A Verembe és Veremb ˝ol m˝uveletek
// végrehajtási ideje maradjon O(1).

TEST_CASE("StackUsingLinkedList 01")
{
	/*StackUsingLinkedList s;
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
	REQUIRE(s.top() == 1);*/
}

TEST_CASE("StackUsingLinkedList 02")
{
	/*StackUsingLinkedList s;
	REQUIRE(s.pop() == -1);
	REQUIRE(s.top() == -1);
	REQUIRE(s.isEmpty() == true);

	s.push(1);
	REQUIRE(s.top() == 1);
	REQUIRE(s.isEmpty() == false);

	REQUIRE(s.pop() == 1);
	REQUIRE(s.top() == -1);
	REQUIRE(s.isEmpty() == true);*/
}

TEST_CASE("StackUsingLinkedList 03")
{
	/*StackUsingLinkedList s;
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
	REQUIRE(s.top() == 7);*/
}
