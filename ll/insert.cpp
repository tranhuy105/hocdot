#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *insertAtEnd(Node *head, int x) {
    if (head == NULL) return new Node(x);
    Node* temp = head;
    while (temp -> next !=NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node(x);
    temp->next = newNode;
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(196);
    head = insertAtEnd(head, 438);
    head = insertAtEnd(head, 552);
    head = insertAtEnd(head, 124);
    head = insertAtEnd(head, 573);

    head = insertAtEnd(head, 318);

    std::cout << "Updated List: ";
    print(head); 

    return 0;
}