#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void hitungJumlahData(Node *head){
	int nilai = 0;
	Node *bantu = head;
	
	while (bantu != NULL){
		nilai++;
		cout<<"Data ke "<<nilai<<": "<<bantu->data<<endl;
		bantu = bantu->next;
	}
	cout<<"Jumlah data : "<<nilai<<endl;
}

int main(){
	Node *head = new Node{10, new Node{20, new Node{30, NULL}}};
	hitungJumlahData(head);
	
	return 0;
}