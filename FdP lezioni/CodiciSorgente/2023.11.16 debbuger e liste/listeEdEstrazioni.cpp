 #include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
void addLastNode(Node*& head, int newData) {
    Node* temp = head;
    while(temp->link != nullptr) {
        temp = temp->link;
    }
    Node* newNode = new Node;
    newNode -> data = newData;
    newNode -> link = nullptr;
    temp->link = newNode;
}
void printList(Node*& head) {
    Node* node = head;
    while (node != nullptr) {
        cout << node->data << endl;
        node=node->link;
    }
}
int estracNodeFromIndex(Node*& head, int index) {
    Node* temp = head;
    for (int i = 0;i< index; i++) {
        temp = temp ->link;
    }
    return temp ->data;
}
int estracNodeFromData(Node*& head, int target) {
    Node* temp = head;
    int index = 1;
    while(temp->data != target) {
        if (temp->link == nullptr) {return 0;}
        temp = temp->link;
        index++;
    }
    return index;
}
int main() {
    //creating the head of the list
    Node* head = new Node;
    head ->data = 0;
    head ->link = nullptr;
    for (int i = 1; i < 20; i++) {
        addLastNode(head,i);
    }
    printList(head);
    cout << "estrac da index: "<<estracNodeFromIndex(head,2) << endl;
    cout << "estrac da data: "<<estracNodeFromData(head,12) -1 << endl;
}
