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
        
        // deleting an element at pos = n (1 - indexed)
        int del(int n);
        
        // Checks if the list is sorted or not 
        bool CheckSort();
        
        // removes duplicate from sorted list
        void RemoveDuplicates();
        
        // Reversing the list using 3 pointers (Pointers sliding method)
        void RevList();
        
        // Recursivly Reversing the List
        void RecRevList();
        void RecRevList(Node *q, Node *p);

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

int LL::del(int n)
{
    if(!head)
        return INT_MIN;
    Node *p = head;
    Node *q = head->next;

    if(n==1)
    {
        int x = head->val;
        head = q;
        delete q;
        return x;
    }

    else
    {
        n--;
        while(--n)
        {
            p = p->next;
            q = q->next;
        }
    
        p->next = q->next;
        int x = q->val;
        delete q;
        return x;
    }
}

bool LL::CheckSort()
{
    if(!head)
    {
        return false;
    }

    Node *p = head;
    Node *q = head->next;

    while(q)
    {
        if(p->val > q->val)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }

    return true;
}

void LL::RemoveDuplicates()
{
    if(!head)
        return;
    
    Node *p = head;
    Node *q = head->next;

    while(q)
    {
        if(p->val != q->val)
        {
            p = q; // same as p = p->next as q is one ahead of p
            q = q->next;
        }

        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }

    return;
}

void LL::RevList()
{
    if(!head)
        return;
    Node *r, *q, *p;
    // all above pointers are in series and moving in series

    r = nullptr;
    q = nullptr;
    p = head;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;
    return;

}

void LL::RecRevList(Node *q, Node *p)
{
    if(p)
    {
        RecRevList(p, p->next);
        p->next = q;
    }

    else
    {
        head = q;
    }
}

void LL::RecRevList()
{
    if(!head)
    {
        return;
    }

    RecRevList(nullptr, head);
}
// Main function to demonstrate linked list operations
int main()
{
    LL l;
    l.append(10);
    l.append(10);
    l.append(10);
    l.append(20);
    l.append(20);
    l.append(20);
    l.append(30);
    l.append(30);
    l.append(30);
    l.append(40);
    l.append(40);
    l.append(40);
    cout << "Original LL: ";
    l.display();

    /* 
    cout << "\nLL after deleting " << l.del(4) << "\n";
    l.display();
    */

    /*
    cout << "\nIs list sorted ? : " << boolalpha << l.CheckSort();
    cout << "\nIs list sorted ? : " << (l.CheckSort() ? "true" : "false");
    */

    /*
    l.RemoveDuplicates();
    cout << "\nAfter Removing Duplicates: ";
    l.display();
    */

    /*
    cout << "\nReversed LL: ";
    l.RevList();
    l.display();
    */

    cout << "\nReversed LL: ";
    l.RecRevList();
    l.display();
    
    return 0;
}
