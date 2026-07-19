// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

// code

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(int n) {
    Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

Node* mergeLists(Node* head1, Node* head2) {
    Node *head = NULL, *tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        Node* newNode = new Node;

        if (head1->data <= head2->data) {
            newNode->data = head1->data;
            head1 = head1->next;
        } else {
            newNode->data = head2->data;
            head2 = head2->next;
        }

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (head1 != NULL) {
        Node* newNode = new Node;
        newNode->data = head1->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        head1 = head1->next;
    }

    while (head2 != NULL) {
        Node* newNode = new Node;
        newNode->data = head2->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        head2 = head2->next;
    }

    return head;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n, m;

    cin >> n;
    Node* head1 = createList(n);

    cin >> m;
    Node* head2 = createList(m);

    Node* merged = mergeLists(head1, head2);

    display(merged);

    return 0;
}