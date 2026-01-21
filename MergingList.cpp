// Merging two List in 'C'

#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void create1(int A[], int n) // For first
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n) // For second
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *A)
{
    struct Node *p = A;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void merge(struct Node *first, struct Node *second)
{
    struct Node *last = NULL;
    
    if(first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    
    while(first && second)
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    if(first)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
}

int main()
{
    int A[] = {5,15,25,35,45,55,65,75,85};
    int m = sizeof(A)/sizeof(A[0]);

    int B[] = {0,10,20,30,40,50,60};
    int n = sizeof(B)/sizeof(B[0]);

    create1(A,m);
    create2(B,n);

    cout << "List A: ";
    display(first);
    
    cout << "List B: ";
    display(second);
    
    merge(first, second);
    
    cout << "A + B: ";
    display(third);

    return 0;
}
