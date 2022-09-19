#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int info;
    node* next;
};

class linkedtype
{
    node*start;

public:
    node* createNewNode(int);
    void createNewList(node*);
    void addAfter(node*);
    void addBefore(node*);
    void addAtEnd(node*);
    void deletion();
    int count();
    void display();
    linkedtype()
    {
        start=NULL;
    }
};

node* linkedtype::createNewNode(int x)
{
    node *newptr;
    newptr=new node();
    newptr->info=x;
    newptr->next=NULL;
    return newptr;
}

void linkedtype::createNewList(node* newptr)
{
    node *temp;
    temp=start;
    start=newptr;
    newptr->next=temp;
}

void linkedtype::addAfter(node *ptr)
{
    int after;
    node*temp;
    cout<<"-> Enter the value after which you want to add node : ";
    cin>>after;
    for (temp=start; temp!=NULL; temp=temp->next)
    {
        if (temp->info==after)
        {
            ptr->next=temp->next;
            temp->next=ptr;
            break;
        }
    }
}


void linkedtype::addAtEnd(node *ptr)
{
    node *temp;
    if (start->next==NULL)
    {
        ptr->next=start->next;
        start->next=ptr;
    }
    else
    {
        for (temp=start; temp!=NULL; temp->next=temp)
        {
            if (temp->next==NULL)
            {
                ptr->next=temp->next;
                temp->next=ptr;
                break;
            }
        }
    }
}
void linkedtype::addBefore(node* ptr)
{
    int before;
    cout<<"-> Enter the value of node before which you want to add the element : ";
    cin>>before;
    node* temp;
    temp=start;
    if (temp->info==before)
    {
        ptr->next=start;
        start=ptr;
    }
    else
    {
        for (temp=start; temp->next!=NULL; temp=temp->next)
        {
            if (temp->next->info=before)
            {
                ptr->next=temp->next;
                temp->next=ptr;
                break;
            }
        }

    }
}

void linkedtype::deletion()
{
    int del;
    cout<<"-> Enter the info part of the node which you want to delete : ";
    cin>>del;
    node *temp;
    if (start->info==del)
    {
        temp=start;
        start=start->next;
        delete temp;
    }
    else
    {
        for (temp=start; temp!=NULL; temp=temp->next)
        {
            if (temp->next->info==del)
            {
                node*temp1;
                temp1=temp->next;
                temp->next=temp1->next;
                delete temp1;
                break;
            }
        }
    }
}

int linkedtype::count()
{
    int flag=0;
    node* temp;
    for (temp=start; temp!=NULL; temp=temp->next)
    {
        flag++;
    }
    return flag;
}

void linkedtype::display()
{
    cout<<endl<<"-> Elements in linked list are : ";
    node* temp;
    for (temp=start; temp!=NULL; temp=temp->next)
    {
        cout<<setw(5)<<temp->info;
    }
    cout<<endl;
}


void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t LINKED LIST OPERATIONS"<<endl;
    cout<<"\t 1. Add new element in Linked List"<<endl;
    cout<<"\t 2. Add new element after given element into Linked List"<<endl;
    cout<<"\t 3. Add new element before given element into Linked List"<<endl;
    cout<<"\t 4. Add new element at the end of Linked List"<<endl;
    cout<<"\t 5. Delete element from Linked List"<<endl;
    cout<<"\t 6. Count the number of elements in Linked List"<<endl;
    cout<<"\t 7. Display the Linked List"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}

int main()
{
    cout<<setw(50)<<endl<<"** IMPLEMENTATION OF LINKED LIST **"<<endl;
    int choice, ele, res;
    char ch='y';
    node *temp1;
    linkedtype list;
    do
    {
        operationList();
        cout<<"-> Select the operation you want to perform : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add new element ** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node* tmp=list.createNewNode(ele);
            list.createNewList(tmp);
            list.display();
            break;
        }
        case 2:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element after given position** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node* tmp=list.createNewNode(ele);
            list.addAfter(tmp);
            list.display();
            break;
        }

        case 3:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element before given position** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node* tmp=list.createNewNode(ele);
            list.addBefore(tmp);
            list.display();
            break;
        }
        case 4:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element at the end** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node* tmp=list.createNewNode(ele);
            list.addAtEnd(tmp);
            list.display();
            break;
        }
        case 5:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Delete the element form list ** "<<endl;
            list.deletion();
            list.display();
            break;
        }
        case 6:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Count number of elements from list ** "<<endl;
            res=list.count();
            cout<<"-> Number of elements in list are : "<<res<<endl;
            list.display();
            break;
        }
        case 7:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Display the elements ** "<<endl;
            list.display();
            break;
        }
        default :
            cout<<endl<<"!! Select a valid operation !!"<<endl<<endl;
        }

        cout<<endl<<"-> Do you want to continue (y/n)? ";
        cin>>ch;
    }
    while(ch=='y' || ch=='Y');
    return 0;
}
