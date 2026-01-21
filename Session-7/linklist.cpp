#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// insert at beginning
void insertBegin(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// insert at end
void insertEnd(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// insert at middle (position based)
void insertMid(Node* &head, int val, int pos) {
    if (pos == 1) {
        insertBegin(head, val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return;

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// delete from beginning
void deleteBegin(Node* &head) {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// delete from end
void deleteEnd(Node* &head) {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// delete from middle using value
void deleteMid(Node* &head, int val) {
    if (head == NULL) return;

    if (head->data == val) {
        deleteBegin(head);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if (temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insertBegin(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    display(head);
    deleteBegin(head);
    display(head);
    deleteMid(head, 30);
    display(head);
    deleteEnd(head);
    display(head);

    return 0;
}

// Leet Code - 142, 206