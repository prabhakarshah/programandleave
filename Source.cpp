// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

void pushNode(Node* &head, int data) {
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

void print(Node* head) {
	while (head != nullptr) {
		cout << head->data << ", ";
		head = head->next;
	}
	cout << endl;
}

void moveNode(Node* &dest, Node* &src) {
	Node* temp = src;
	src = src->next;
	dest->next = temp;
	dest = temp;
}
//Merge two lists given in sorted order
Node* mergeList(Node* &list1, Node* &list2) {
	Node dummy(0);
	Node* outList = &dummy;
	while (true) {
		if (list1 == nullptr) {
			outList->next = list2;
			break;
		}
		if (list2 == nullptr) {
			outList->next = list1;
		}

		if (list1->data <= list2->data) {
			moveNode(outList, list1);
		}
		else
			moveNode(outList, list2);

		outList = outList->next;
	}
	return outList;
}

Node* makeList() {
	Node *head =  nullptr;
	pushNode(head, 1);
	pushNode(head, 2);
	pushNode(head, 3);
	pushNode(head, 4);
	pushNode(head, 5);
	pushNode(head, 7);

	return head;
}

Node* makeList1() {
	Node *head = nullptr;
	pushNode(head, 1);
	pushNode(head, 3);
	pushNode(head, 4);

	return head;
}
void reverse(Node* &head) {
	Node *current = head;
	Node* prev = nullptr, *next = nullptr;

	while (true)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		if (current == nullptr)
			break;

	}

	head = prev;
}

Node* makeList2() {
	Node *head = nullptr;
	pushNode(head, 2);
	pushNode(head, 5);
	pushNode(head, 7);

	return head;
}

int main() {
	Node* head = makeList();
	print(head);
	reverse(head);
	print(head);

	return 0;

}

