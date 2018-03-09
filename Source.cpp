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

int main(){


}