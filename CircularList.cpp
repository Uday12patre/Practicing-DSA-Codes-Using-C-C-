// Implementing Circular Linked List

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    Node *next;
}*head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    
    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{  
    do{
        printf("%d ", p->data);
        p =p->next;
    } while(p!=head);
}

void Rdisplay(struct Node *p)
{
    static int flag = 0;
    if(p!=head || flag==0)
    {
        flag = 0;
        printf("%d ", p->data);
        display(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {2,3,4,5,6,7,7};
    int m = sizeof(A)/sizeof(A[0]);
    
    create(A, m);
    Rdisplay(head);
    
    return 0;
}
