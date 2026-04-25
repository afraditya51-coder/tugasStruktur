#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void Total(Node *head){
	int total = 0;
	Node *bantu = head;
	int i = 1;
	
	while (bantu != NULL){
		cout<<"Data ke "<< i <<": "<<bantu->data<<endl;
		total += bantu->data;
		bantu = bantu->next;
		i++;
	}
	cout<<"Total nilai adalah : "<<total<<endl;
}

int main(){
	Node *head = new Node{10, new Node{20, new Node{30,NULL}}};
	Total(head);
	
	return 0;
}