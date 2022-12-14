#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class node
{
public:
    T info;
    node<T> *next;

public:
    node(T x, node<T> *n = NULL)
    {
        info = x;
        next = n;
    }
};

template <class T>
class queuetype
{
    node<T> *f, *r;

public:
    queuetype()
    {
        f = r = NULL;
    }
    void enqueue(T x);
    int dequeue();
    int isempty();
    void count(node<T> *);
    void rearmost();
    void display();
};
template <class T>
int queuetype<T>::isempty()
{
    if (f == NULL)
        return 1;
    else
        return -1;
}
template <class T>
void queuetype<T>::count(node<T> *temp)
{
    int ct = 0;
    if (f == NULL)
    {
        cout << "\n Queue is empty "
             << " Nodes are : " << ct;
    }
    else
    {
        for (temp = f; temp != NULL; temp = temp->next)
        {
            ct++;
        }
        cout << "\n Total No. of Nodes in Queue : " << ct;
    }
}
template <class T>
void queuetype<T>::rearmost()
{
    node<T> *temp;
    if (r == NULL)
    {
        cout << "\n Queue is empty ";
    }
    else
    {
        temp = r;
        cout << "\n Rearmost is : " << temp->info;
    }
}
template <class T>
int queuetype<T>::dequeue()
{
    int x;
    node<T> *temp;
    x = f->info;
    temp = f;
    f = f->next;
    delete (temp);
    if (f == NULL)
        f = r = NULL;
    return (x);
}
template <class T>
void queuetype<T>::enqueue(T x)
{
    node<T> *temp;
    temp = new node<T>(x);
    if (f == NULL)
    {
        f = r = temp;
    }
    else
    {
        r->next = temp;
        r = temp;
    }
}
template <class T>
void queuetype<T>::display()
{
    if (f == NULL)
    {
        cout << "\n Queue is empty ! Nothing to display ";
    }
    else
    {
        cout << "\n Contents of the stack starting from rearmost point are : ";
        node<T> *temp;
        for (temp = f; temp != NULL; temp = temp->next)
        {
            cout << temp->info << "\t";
        }
    }
}

void operationList()
{
    cout << endl
         << endl;
    cout << setw(40) << "=======================" << endl;
    cout << "\t \t CIRCULAR QUEUE OPERATIONS (LINKED IMPLEMENTATION) " << endl;
    cout << "\t 1. Add elements into Queue/ ENQUEUE" << endl;
    cout << "\t 2. Delete element from Queue/ DEQUEUE" << endl;
    cout << "\t 3. Display the elements of the queue" << endl;
    cout << "\t 4. Check if Queue is empty" << endl;
    cout << "\t 5. Print rearmost element" << endl;
    cout << "\t 6. Count the elements of the queue" << endl;
    cout << setw(40) << "=======================" << endl
         << endl;
    return;
}

int main()
{
    cout << setw(50) << endl
         << "** QUEUE IMPLEMENTATION USING CIRCULAR ARRAY **" << endl;
    int choice, ele, res;
    char ch = 'y';
    queuetype<int> queue;
    operationList();
    while (ch == 'y' || ch == 'Y')
    {

        cout << "-> What operation do you want to perform : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl
                 << "\t ** OPERATION CHOSEN : Enter Elements ** " << endl
                 << endl;
            cout << "-> Enter the element in the queue : ";
            cin >> ele;
            queue.enqueue(ele);
            queue.display();
            break;

        case 2:
            cout << endl
                 << "\t ** OPERATION CHOSEN : Delete Elements ** " << endl
                 << endl;
            res = queue.dequeue();
            cout << " -- Element Deleted : " << res << endl;
            queue.display();
            break;
        case 3:
            cout << endl
                 << "\t ** OPERATION CHOSEN : Display Circular Queue ** " << endl
                 << endl;
            queue.display();
            break;
        case 4:
            cout << endl
                 << "\t ** OPERATION CHOSEN : Checking for Underflow ** " << endl
                 << endl;
            res = queue.isempty();
            if (res == 1)
                cout << "Queue is Empty! " << endl;
            else
                cout << "Queue is not Empty! " << endl;
            queue.display();
            break;

        case 5:
            cout << endl
                 << "\t ** OPERATION CHOSEN :Print Rearmost element ** " << endl
                 << endl;
            queue.rearmost();
            break;

        case 6:
            cout << endl
                 << "\t ** OPERATION CHOSEN : Count Queue Elements ** " << endl
                 << endl;
            node<int> *temp;
            queue.count(temp);
            break;
        }

        cout << endl
             << "-> Do you want to continue (y/n) : ";
        cin >> ch;
    }
    cout << endl
         << "\t\t *** PROGRAM ENDS HERE ***" << endl
         << endl;
    return 0;
}
