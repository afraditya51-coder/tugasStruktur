#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int nilai) {
    Node* baru = new Node(); 
    baru->data = nilai;      
    baru->next = top;        
    top = baru;    

    cout << "Push -> " << nilai << endl;
}


void pop() {
    if (top == NULL) {
        cout << "Stack kosong! Tidak bisa pop." << endl;
        return;
    }

    Node* temp = top;       
    int nilai = top->data;  
    top = top->next;        
    delete temp;            

    cout << "Data yang diambil: " << nilai << endl;
}

void peek() {
    if (top == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Data paling atas: " << top->data << endl;
}

void tampil() {
    if (top == NULL) {
        cout << "Stack kosong." << endl;
        return;
    }

    cout << "Isi stack (atas ke bawah): ";
    Node* node = top;
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL) cout << " -> ";
        node = node->next;
    }
    cout << " -> NULL" << endl;
}

int main() {

    push(10);
    push(20);
    push(30);
    cout << endl;

    tampil();
    cout << endl;

    peek();
    cout << endl;

    pop();
    pop();
    cout << endl;

    tampil();

    return 0;
}