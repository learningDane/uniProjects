#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

void addFirstNode(Node* & head, int newData) {
    Node* newNode = new Node;
    newNode ->data=newData;
    newNode ->link=head;
    head = newNode;
}
void addLastNode(Node* & head, int data) {
    Node* temp= head;
    while (temp->link != nullptr) {
        temp = temp -> link;
    }
    Node* newNode = new Node;
    newNode -> data= data;
    temp->link=newNode;
}
void printList(Node* & head) {
    Node*temp = head;
    while(temp->link != nullptr) {
        cout << temp -> data << endl;
        temp = temp->link;
    }
}
void deleteList(Node*&head) {
    while (head != nullptr) {
        Node* next = head->link;
        delete head;
        head = next;
    }
}
int main(){
    Node* head = new Node;
    head ->data=20;
    head ->link= nullptr;
    addFirstNode(head,34);
    addLastNode(head,87);
    printList(head);
    deleteList(head);
}