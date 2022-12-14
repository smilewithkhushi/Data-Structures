//. Include functions for insertion, deletion and search of a number,
// reverse the list and
//concatenate two linked lists (include a function and also overload operator +).

#include <iostream>
#include <iomanip>
using namespace std;

template<class t>
struct node
{
    t info;
    node* next;
};

template <class t>
class linkedtype
{
    public:

    node<t>* start;

    node<t>* createNewNode(t);
    void createNewList(node<t>*);
    //functions for adding the node
    void addAfter(node<t>*);
    void addBefore(node<t>*);
    void addAtEnd(node<t>*);
    //function for deletion
    void deletion();
    int count();
    //function for reversing
    void reverse();
    //function to perform searching
    void searching(t ele);
    void concatenate(node<t>*);
    void display();
    linkedtype()
    {
        start=NULL;
    }
};

template<class t>
node<t>* linkedtype<t>::createNewNode(t x)
{
    node<t> *newptr;
    newptr=new node<t>();
    newptr->info=x;
    newptr->next=NULL;
    return newptr;
}

template<class t>
void linkedtype<t>::createNewList(node<t>* newptr)
{
    node<t>* temp;
    temp=start;
    start=newptr;
    newptr->next=temp;
}

template <class t>
void linkedtype<t> ::addAfter(node<t>*ptr)
{
    t after;
    node<t>*temp;
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

template <class t>
void linkedtype<t>::addAtEnd(node<t>*ptr)
{
    node<t> *temp;
    if (start->next==NULL)
    {
        ptr->next=start->next;
        start->next=ptr;
    }
    else
    {
        for (temp=start; temp!=NULL; temp=temp->next)
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

template <class t>
void linkedtype<t>::addBefore(node<t>* ptr)
{
    t before;
    cout<<"-> Enter the value of node before which you want to add the element : ";
    cin>>before;
    node<t>* temp;
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
            if (temp->next->info==before)
            {
                ptr->next=temp->next;
                temp->next=ptr;
                break;
            }
        }

    }
}

template <class t>
void linkedtype<t>::deletion()
{
    t del;
    cout<<"-> Enter the info part of the node which you want to delete : ";
    cin>>del;
    node<t> *temp;
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
                node<t>* temp1;
                temp1=temp->next;
                temp->next=temp1->next;
                delete temp1;
                break;
            }
        }
    }
}

template <class t>
int linkedtype<t>::count()
{
    int flag=0;
    node<t>* temp;
    for (temp=start; temp!=NULL; temp=temp->next)
    {
        flag++;
    }
    return flag;
}

template<class t>
void linkedtype<t>::searching(t ele){
    node<t>* temp;
    for (temp=start; temp!=NULL; temp=temp->next){
        if (temp->info==ele){
            cout<<"SEARCH RESULT :: Element found!"<<endl;
            return;
        }
    }
    cout<<"SEARCH RESULT :: Element not found!"<<endl;
}

template <class t>
void linkedtype<t>::reverse()
{
    node<t> *rev;           //first node for reversed list or last node of original list
    node<t>* current = start;
    node<t> *prev = NULL, *next = NULL;
 
    while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
    }
    rev = prev;
    
    cout<<endl<<"-> Reversed Linked List : ";
    
    node<t>* temp;
    for (temp=rev; temp!=NULL; temp=temp->next)
    {
        cout<<setw(5)<<temp->info;
    }
    cout<<endl;
}

template <class t>
void linkedtype<t>::concatenate(node<t>* newlst)
{
    node<t>* temp=start;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newlst;
    return ; 
}


template <class t>
void linkedtype<t>::display()
{
    cout<<endl<<"-> Elements in linked list are : ";
    node<t>* temp;
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
    cout<<"\t 7. Search a given number/element out of elements in Linked List"<<endl;
    cout<<"\t 8. Reverse the given Linked List"<<endl;
    cout<<"\t 9. Concatenate two Linked Lists"<<endl;
    cout<<"\t 10. Display the Linked List"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}

template <class t> void operations(linkedtype<t> list){
    int choice, res;
    t ele;
    char ch='y';
    node<t>*temp1;
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
            node<t>* tmp=list.createNewNode(ele);
            list.createNewList(tmp);
            list.display();
            break;
        }
        case 2:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element after given position** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node<t>* tmp=list.createNewNode(ele);
            list.addAfter(tmp);
            list.display();
            break;
        }

        case 3:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element before given position** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node<t>* tmp=list.createNewNode(ele);
            list.addBefore(tmp);
            list.display();
            break;
        }
        case 4:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element at the end** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node<t>* tmp=list.createNewNode(ele);
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
        case 7 : {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Searching the element from list ** "<<endl;
            t elem;
            cout<<"-> Enter the element to be searched : ";
            cin>>elem;
            list.searching(elem);
            break;
            
        }

        case 8 : {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Reverse the Linked list ** "<<endl;
            list.display();
            list.reverse();
            break;
            
        }

        case 9 : {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Concatenate two linked lists  ** "<<endl;
            t elem;
            cout<<"-> Enter the element for second Linked List : ";
            cin>>elem;
            linkedtype<t> lst2;
            node<t>* tmp=lst2.createNewNode(ele);
            lst2.createNewList(tmp);

            list.concatenate(lst2.start);
            list.display();
            break;
            
        }

        case 10:
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

}

int main()
{
    cout<<setw(50)<<endl<<"** IMPLEMENTATION OF LINKED LIST **"<<endl<<endl;
    int choice;
    cout<<"-> Which type of LinkedList do you want to create?? \n1. String \n2. Integer \n3. Floating Number/Decimal \n ~ Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1: {
            linkedtype<string> list1;
            operations(list1);
            break;
        }  
        case 2: {
            linkedtype<int> list2;
            operations(list2);
            break;
        } 
        case 3: {
                linkedtype<float> list3;
                operations(list3);
                break;
        } 
        default : cout<<"~~ INVALID TYPE ! TRY AGAIN ~~"<<endl<<endl;
    }
    return 0;
}

