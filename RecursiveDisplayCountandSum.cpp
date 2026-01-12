// SLL with Recursive Display, Count and Sum

#include<iostream>
#include<climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SLL
{
    private:
        Node *head, *tail;

        // Recursive function to display linked list elements (helper)
        void display(Node *p);

        // Recursive function to count number of nodes (helper)
        int count(Node *p);

        // Recursive function to calculate Sum Of All elements (helper)
        int SOA(Node *p);

    public:
        // Constructor to initialize empty linked list
        SLL() : head(NULL), tail(NULL) {};

        // Function to append a new node at the end
        void append(int n);

        // Public function to display linked list
        void display();

        // Public function to count number of elements
        int count();

        // Public function to calculate sum of all elements
        int SOA();
};

// Function to insert a node at the end of the linked list
void SLL::append(int n)
{
    Node *nn = new Node;
    if(!nn)
        return;

    Node *p = head;

    nn->data = n;
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

// Wrapper function to start recursive display
void SLL::display()
{
    display(head);
    return;
}

// Recursive function to display linked list in reverse order
void SLL::display(Node* p)
{
    if(!p)
        return;

    display(p->next);
    cout << p->data << " ";

    return;
}

// Wrapper function to count number of nodes
int SLL::count()
{
    return count(head);
}

// Recursive function to count nodes in linked list
int SLL::count(Node *p)
{
    if(!p)
    {
        return 0;
    }

    return 1 + count(p->next);
}

// Wrapper function to calculate sum of all elements
int SLL::SOA()
{
    return SOA(head);
}

// Recursive function to calculate sum of all node data
int SLL::SOA(Node *p)
{
    if(p)
    {
        return p->data + SOA(p->next);
    }

    return 0;
}

int main()
{
    SLL s;
    s.append(10);
    s.append(20);
    s.append(30);
    s.append(40);
    s.append(50);

    cout << "SLL: ";
    s.display();
    cout << endl;

    cout << "No. of Elements in LL is: " << s.count() << endl;
    cout << "Sum of All elements in LL is: " << s.SOA();

    return 0;
}
