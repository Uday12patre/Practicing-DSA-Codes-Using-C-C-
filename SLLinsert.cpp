/* 
Single Linked List
LL()
append()
insertfirst()
insert()
appendsort()
display()
main()
*/

#include<bits/stdc++.h>
using namespace std;

// Structure representing a single node of the linked list
struct Node
{
    int val;
    struct Node *next; // Self referential pointer to 'Node'
};

// Linked List class containing head and tail pointers
class LL
{
    private:
        struct Node *head, *tail;
    public:
        // Constructor to initialize an empty linked list
        LL() : head(NULL), tail(NULL) {};

        // Appends a node at the end of the linked list
        void append(int n);

        // Inserts a node at the beginning of the linked list
        void insertfirst(int n);

        // Inserts a node at a given position (1-based index)
        void insert(int i, int n);

        // Inserts a node in a sorted linked list at the correct position
        void appendsort(int n);

        // Displays all elements of the linked list
        void display();
};

// Function to append a node at the end of the linked list
void LL::append(int n)
{
    struct Node *nn = new Node;
    struct Node *p = head;
    if(!nn)
        return;

    nn->val = n;
    nn->next = NULL;

    if(!head)
    {
        head = tail = nn;
        return;
    }

    tail->next = nn;
    tail = nn;
    return;
    
}

// Function to display the linked list elements
void LL::display()
{
    Node *p = head;
    while(p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return;
}

// Function to insert a node at the beginning of the linked list
void LL::insertfirst(int n)
{
    Node *nn = new Node;
    if(!nn)
        return;
    
    nn->val = n;
    nn->next = head;
    head = nn;
    return;
}

// Function to insert a node at a specified position
void LL::insert(int i, int n)
{
    Node *nn = new Node;
    Node *p1 = head;
    Node *p2 = head->next;

    if(!nn)
        return;
    
    if(i > 1)
    {
        int count = 1;
        while(count != i)
        {
            count++;
            p1 = p1->next;
            p2 = p2->next;
    
            if(i-1 == count)
            {
                nn->val = n;
                nn->next = p2;
                p1->next = nn;
    
                break;
            }
            
        }
    }

    if(i==1)
    {
        insertfirst(n);
        return;
    }

    return;
}

// Function to insert a node into a sorted linked list
void LL::appendsort(int n)
{
    Node *nn = new Node;
    Node *p = head;

    while(p && p->next)
    {
        if(!p->next->next && p->next->val < n)
        {
            nn->val = n;
            nn->next = NULL;
            p = p->next;
            p->next = nn;
            break;
        }

        if(p->val <= n && n <= p->next ->val)
        {
            nn->val = n;
            nn->next = p->next;
            p->next = nn;
            break;
        }
        p = p->next;
    }

    return;
}

// Main function to demonstrate linked list operations
int main()
{
    LL l;
    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);
    cout << "Original LL: ";
    l.display();

    l.appendsort(45);
    cout << "\nLL after inserting 45: ";
    l.display();

    l.appendsort(50);
    cout << "\nLL after inserting 50: ";
    l.display();

    l.appendsort(22);
    cout << "\nLL after inserting 22: ";
    l.display();

    l.appendsort(44);
    cout << "\nLL after inserting 44: ";
    l.display();
    return 0;
}
