#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; // Global pointer

struct Node *first1 = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void RDisplay(struct Node *p) // Recursive Display function
{
    if (p)
    {
        cout << p->data << " ";
        RDisplay(p->next);
    }
    cout << "\n\n";
}

void ReverseDisplay(struct Node *p) // Recursive reverse Display function
{
    if (p)
    {
        RDisplay(p->next);
        cout << p->data << " ";
    }
}

int Count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int RCount(struct Node *p)
{
    if (p)
    {
        return RCount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

int Sum(struct Node *p)
{
    int s = 0;
    while (p)
    {
        s = s + p->data;
        p = p->next;
    }
    return s;
}

int RSum(struct Node *p)
{
    if (p)
    {
        return RSum(p->next) + p->data;
    }
    else
    {
        return 0;
    }
}

int Max(struct Node *p)
{
    int m = INT32_MIN;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int RMax(struct Node *p)
{
    int x = 0;
    if (!p)
        return INT32_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

struct Node *LSearch(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
        {
            return (p);
        }
        p = p->next;
    }
    return NULL;
}

struct Node *RLinearSearch(struct Node *p, int key)
{
    if (!p)
    {
        return NULL;
    }
    else if (key == p->data)
    {
        return (p);
    }
    else
    {
        RLinearSearch(p->next, key);
    }
};

struct Node *ImpLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
};

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(struct Node *p, int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (!p)
    {
        first = last = t;
    }
    else
    {
        last = p;
        while (last->next)
        {
            last = last->next;
        }
        last->next = t;
        last = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (!p)
    {
        first = t;
    }
    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    if (p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > Count(p))
    {
        return x;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

bool isSorted(struct Node *p)
{
    int x = INT64_MIN;
    while (p)
    {
        if (p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p) // Reversing array using auxilary verb
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * (Count(p)));
    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    i--;
    q = p;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
    {
        last->next=p;
    }
    else{
        last->next=q;
    }

}

int main()
{
    /*int A[]={3,12,10};
    create(A,3);*/
    // ReverseDisplay(first);
    // cout<<"The length of the list is : "<<RCount(first)<<endl<<endl;
    // cout<<"Sum of elements : "<<RSum(first)<<endl<<endl;
    // cout<<"Max : "<<RMax(first)<<endl<<endl;
    /*
       struct Node *temp;
       temp=ImpLSearch(first,30);
       if(temp)
       {
            cout<<"Key found at : "<<temp<<endl<<endl;
       }
       else
       {
           cout<<"Key not found!"<<endl;
       }
       Display(first);
       */
    /*cout<<"\n\n";
    cout<<"\nBefore insertion : ";
    Display(first);
    cout<<"\n\nAfter insertion at pos 0 : ";
    Insert(first,0,60);
    Display(first);
    cout<<"\n\nAfter insertion at pos 2 : ";
    Insert(first,2,80);
    Display(first);
    cout<<"\n\n";
    */
    /*
    Insert(first,0,10);
    Insert(first,1,20);
    Insert(first,2,30);
    Insert(first,3,40);
    Insert(first,4,50);
    Insert(first,5,60);

    */

    /*
    InsertLast(first,20);
    InsertLast(first,30);
    InsertLast(first,40);
    InsertLast(first,50);
    InsertLast(first,60);

    */

    /*
    cout<<"\n\n\n";
    Display(first);
    cout<<"\n\n\n";

    SortedInsert(first, 45);
    SortedInsert(first,34);
    SortedInsert(first,23);
    SortedInsert(first,10);
    SortedInsert(first,64);
    Display(first);
    */
    /*
    cout<<"\nDeleting node 1 : "<<Delete(first,1)<<endl;
    cout<<"\nDeleting node 3 : "<<Delete(first,3)<<endl;
    cout<<"\n";
    Display(first);
    */

    // if(isSorted(first))
    // {
    //     cout<<"\n\nThe list is sorted!";
    // }
    // else{
    //     cout<<"\n\nNot sorted!";
    // }

    // Reverse3(NULL,first);

    // Reverse1(first);
    // Reverse2(first);
    /*
    Reverse3(NULL, first);
    Display(first);
    cout<<endl;
    */

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    int B[] = {15, 25, 35, 45, 55};
    create2(B, 5);

    // cout<<"First list : "<<endl;
    // Display(first);
    // cout<<"\nSecond list : "<<endl;
    // Display(second);

    //Concat(first, second);
    Merge(first,second);
    Display(third);

    return 0;
}
