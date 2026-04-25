#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

void list(Node** head, Node**tail){
	Node *node1 = new Node();
	Node *node2 = new Node();
	Node *node3 = new Node();
	
	node1->prev = NULL;
	node1->data = 10;
	node1->next = node2;
	
	node2->prev = node1;
	node2->data = 20;
	node2->next = node3;
	
	node3->prev = node2;
	node3->data = 30;
	node3->next = NULL;
	
	*head = node1;
	*tail = node3;
}

void push_head(Node* head){
	Node* node = head;
	while (node != NULL){
		cout<<node->data<<endl;
		node = node->next;
	}
	cout<<endl;
}

void push_tail(Node* tail){
	Node* node = tail;
	while (node != NULL){
		cout<<node->data<<endl;
		node = node->prev;
	}
	cout<<endl;
}

void tampil(Node* head){
	Node* node = head;
	int i = 1;
	int jumlah = 0;
	
	while (node != NULL){
		cout<<"Data ke "<< i <<" : "<<node->data<<endl;
		node = node->next;
		i++;
		jumlah++;
	}
	cout<<"Jumlah data : "<<jumlah<<endl;
}

int main(){
	Node* head = NULL;
	Node* tail = NULL;
	
	list(&head, &tail);
	
	push_head(head);
	push_tail(tail);
	
	tampil(head);
	
	return 0;
	
}