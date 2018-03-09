#include <iostream>

using namespace std;
struct Node{
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		next = nullptr;
	}
};

void push(Node* &head, int data){
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

void print(Node* head){
	while (head != nullptr){
		cout << head->data<<", ";
		head = head->next;
	}
	cout << endl;
}

void moveNode(Node* &src, Node* &dest){
	Node* temp = src;
	src = src->next;
	dest->next = temp;
	dest = temp;
}
//Merge two lists given in sorted order
Node* mergeList(Node* &list1, Node* &list2){
	Node dummy(0);
	Node* outList = &dummy;
	while (true){
		if (list1 == nullptr){
			outList->next = list2;
			break;
		}
		if (list2 == nullptr){
			outList->next = list1;
		}

		if (list1->data <= list2->data){
			moveNode(outList->next, list1);
		}
		else
			moveNode(outList->next, list2);

		outList = outList->next;
	}
}

int main(){


}
