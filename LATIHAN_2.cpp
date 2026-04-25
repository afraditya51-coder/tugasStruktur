#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void cariTerbesar(Node *head){
	
	int nilaiTerbesar = head->data;
	Node *bantu = head;
	int i = 1;
	
	while (bantu != NULL){
		cout<<"Data ke "<< i <<": "<<bantu->data<<endl;
		if (bantu->data > nilaiTerbesar) nilaiTerbesar = bantu->data;
		bantu = bantu->next;
		i++;
	}
	cout<<"Nilai terbesar adalah : "<<nilaiTerbesar<<endl;
}

int main(){
	Node *head = new Node{10, new Node{20, new Node{30, NULL}}};
	cariTerbesar(head);
	
	return 0;
}