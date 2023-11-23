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
void inserisciOrdinato(Node*& head, int num) {
    Node* newNode = new Node;
    newNode->data = num;
    newNode->link = nullptr;

    if (head == nullptr || head->data >= num) {
        newNode->link = head;
        head = newNode;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data < num) {
        previous = current;
        current = current->link;
    }

    previous->link = newNode;
    newNode->link = current;
}
int main() {
    Node* head = nullptr;
    int num;
    cout << "Inserire 6 numeri:" << endl;
    for (int i = 0; i < 6; i++) {
        cin>> num;
        inserisciOrdinato(head,num);
    }
    cout << "insert new number" << endl;
    cin >> num;
    inserisciOrdinato(head, num);
    printList(head);
    //deallocate memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->link;
        delete temp;
    }
}