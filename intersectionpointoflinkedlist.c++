// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

// code


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int length(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n;

    Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(head1, tail1, x);
    }

    cin >> m;

    Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        insert(head2, tail2, x);
    }

    int len1 = length(head1);
    int len2 = length(head2);

    Node *p1 = head1;
    Node *p2 = head2;

    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff--)
            p1 = p1->next;
    }
    else
    {
        int diff = len2 - len1;
        while (diff--)
            p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data == p2->data)
        {
            cout << p1->data;
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    cout << "No Intersection";

    return 0;
}