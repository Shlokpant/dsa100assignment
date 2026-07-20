// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

// code


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Node* deleteFirstOccurrence(Node* head, int key) {
    if (head == NULL)
        return head;

    // If first node contains the key
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insert(head, x);
    }

    int key;
    cin >> key;

    head = deleteFirstOccurrence(head, key);

    display(head);

    return 0;
}