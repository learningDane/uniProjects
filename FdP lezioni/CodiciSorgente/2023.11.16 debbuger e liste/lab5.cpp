#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
void printList(Node*& head) {
    Node* temp = new Node;
    temp->link = head->link;
    temp->data = head->data;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->link;
    }
    delete temp;
}
int main() {
    Node* head = new Node;
    head->data= 50;
    head->link = nullptr;
    //aggiungere 60 in fondo
    Node* nodo2 = new Node;
    nodo2->data=60;
    nodo2->link=nullptr;
    head->link = nodo2;
    //agg 70 in testa
    Node* nodo3 = new Node;
    nodo3->data=head->data;
    nodo3->link=head->link;
    head->link=nodo3;
    head->data=70;
    //
    printList(head);
    //
    head->link = nodo2;
    delete nodo3;
    //
    printList(head);
}