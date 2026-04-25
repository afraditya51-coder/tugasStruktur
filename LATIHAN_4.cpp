#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};


void push_tail(Node **head, int nilai){
	Node *node = new Node{nilai, NULL};
	if (*head == NULL){
		*head = node;
		return;
	}
	Node *bantu = *head;
	while (bantu->next != NULL) bantu = bantu->next;
	bantu->next = node;
}

void push_head(Node **head, int nilaiBaru){
	Node *node = new Node();
	node->data = nilaiBaru;
	node->next = *head;
	*head = node;
}

void show_list(Node *node){
	int i = 1;
	while (node != NULL){
		cout<<node->data<<" -> ";
		node = node->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
	Node *head = NULL;
	int n, nilai, tambahData;
	
	cout<<"Masukan jumlah data : ";
	cin>>n;
	
	for (int i = 1; i <= n; i++){
		cout<<"Masukan data ke "<<i<<" : ";
		cin>>nilai;
		push_tail(&head, nilai);
	}
	cout<<endl;
	cout<<"Masukan data yang ditambahkan di awal : ";
	cin>>tambahData;
	
	push_head(&head, tambahData);
	
	cout<<"\nData setelah ditambah diawal"<<endl;
	show_list(head);
	
	return 0;
}