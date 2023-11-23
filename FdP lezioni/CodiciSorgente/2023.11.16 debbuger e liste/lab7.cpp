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
void inserisciOrdinato(Node*& head, int newNum) {
    Node* newNode = new Node;
    newNode->data = newNum;
    newNode->link = nullptr;
    Node* current = head;
    Node* previous = nullptr;
    if (newNum <= head->data || head == nullptr) {
        newNode->link= head;
        head = newNode;
        return;
    }
    while (current != nullptr) {

        if (newNum <= current->data) {
            previous->link = newNode;
            newNode->link= current;
            return;
        }

        previous = current;
        current = current ->link;
    }
}
void insLast(Node*& head, int num) {
    Node* current = head;
    Node* newNode = new Node;
    newNode->data=num;
    newNode->link=nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        while (current->link != nullptr) {
            current = current -> link;
        }
        current->link = newNode;
    }
}
int main() {
    Node* head = nullptr;
    int*lista = new int[6]{2,5,12,45,78,92};
    for (int i = 0; i < 6; i++) {
        insLast(head, lista[i]);
    }
    delete[] lista;
    printList(head);
    cout << endl;
    //adesso ho una lista ordinata
    //inserisco un numero in maniera ordinata
    int newNum = 1;
    inserisciOrdinato(head,newNum);
    printList(head);
}