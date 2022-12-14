#include <iostream>
using namespace std;

template <class Type> class node
{
public:
    Type info;
    node<Type> *pre, *next;
    node()
    {
        pre = next = NULL;
    }
    node(Type x, node<Type> *n = 0, node<Type> *p = 0)
    {
        info = x;
        pre = p;
        next = n;
    }
};

template <class Type>
class dllist
{
private:
    node<Type> *head;
    node<Type> *tail;

public:
    dllist()
    {
        head = tail = NULL;
    }
    int isempty();
    void addtohead(Type x);
    void addtotail(Type x);
    Type deletefromhead();
    Type deletefromtail();
    void deletenode(Type x);
    node<Type> *isinlist(Type x);
    void concat(dllist<Type> l1);
    void reverse(dllist<Type> l1);
    dllist operator+(dllist<Type> l1);
    Type input();
    void display();
    int count();
    void add_at_i(Type, int);
    Type remove_at_i(int);
};

template <class Type>
int dllist<Type>::isempty()
{
    if (head == 0 && tail == 0)
        return 1;
    else
        return 0;
}

template <class Type>
void dllist<Type>::addtohead(Type x)
{
    node<Type> *temp = new node<Type>(x);
    if (isempty())
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

template <class Type>
void dllist<Type>::addtotail(Type x)
{
    node<Type> *temp = new node<Type>(x);
    if (isempty())
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
}

template <class Type>
void dllist<Type>::add_at_i(Type x, int i)
{
    node<Type> *temp = new node<Type>(x);
    if (i < 1 || i > (*this).count() + 1)
    {
        cout << "Enter valid position\n";
    }
    else if (i == 1)
    {
        addtohead(x);
    }
    else if (i == count() + 1)
    {
        addtotail(x);
    }
    else
    {
        node<Type> *nptr = head;
        for (int j = 1; j < i - 1; j++)
        {
            nptr = nptr->next;
        }
        temp->next = nptr->next;
        temp->pre = nptr;
        nptr->next = temp;
    }
}

template <class Type>
Type dllist<Type>::remove_at_i(int i)
{
    Type del;
    if (i < 1 || i > (*this).count() + 1)
    {
        cout << "Enter valid position\n";
    }
    else if (i == 1)
    {
        del = (*this).deletefromhead();
    }
    else if (i == count() + 1)
    {
        del = (*this).deletefromtail();
    }
    else
    {
        node<Type> *nptr = head;
        for (int j = 1; j < i - 1; j++)
        {
            nptr = nptr->next;
        }
        del = nptr->next->info;
        delete nptr->next;
        nptr->next = nptr->next->next;
    }
    return del;
}

template <class Type>
Type dllist<Type>::deletefromhead()
{
    Type del;
    del = head->info;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        delete head->pre;
        head->pre = NULL;
    }
    return del;
}

template <class Type>
Type dllist<Type>::deletefromtail()
{
    Type del;
    del = tail->info;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->pre;
        delete tail->next;
        tail->next = NULL;
    }
    return del;
}

template <class Type>
void dllist<Type>::concat(dllist<Type> l1)
{
    node<Type> *temp;
    ;
    temp = l1.head;
    while (temp != NULL)
    {
        (*this).addtotail(temp->info);
        temp = temp->next;
    }
}

template <class Type>
dllist<Type> dllist<Type>::operator+(dllist<Type> l1)
{
    node<Type> *temp;
    dllist l3;
    if (!(*this).isempty())
    {
        temp = (*this).head;
        while (temp != NULL)
        {
            l3.addtotail(temp->info);
            temp = temp->next;
        }
    }
    if (!l1.isempty())
    {
        temp = l1.head;
        while (temp != NULL)
        {
            l3.addtotail(temp->info);
            temp = temp->next;
        }
    }
    return l3;
}

template <class Type>
void dllist<Type>::deletenode(Type x)
{
    node<Type> *temp, *prev;
    Type del;
    if (head == tail && head->info == x)
    {
        delete head;
        ;
        head = tail = NULL;
    }
    else if (head->info == x)
    {
        del = deletefromhead();
        cout << del << "has been deleted\n";
    }
    else
    {
        prev = head;
        temp = head->next;
        while ((temp != NULL) && (temp->info != x))
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            prev->next = temp->next;
            if (temp == tail)
                tail = prev;
            delete temp;
        }
        else
            cout << "Element not found\n";
    }
}

template <class Type>
node<Type> *dllist<Type>::isinlist(Type x)
{
    node<Type> *temp;
    if (head->info == x)
    {
        return head;
    }
    else if (tail->info == x)
    {
        return tail;
    }
    else
    {
        temp = head;
        while ((temp != NULL) && (temp->info != x))
        {
            temp = temp->next;
        }
        if (temp != NULL)
            return temp;
        else
            return NULL;
    }
}

template <class Type>
void dllist<Type>::reverse(dllist<Type> l1)
{
    node<Type> *temp;
    temp = l1.head;
    while (temp != 0)
    {
        (*this).addtohead(temp->info);
        temp = temp->next;
    }
    display();
}

template <class Type>
Type dllist<Type>::input()
{
    Type n;
    cout << "Enter the number\n";
    cin >> n;
    return n;
}

template <class Type>
void dllist<Type>::display()
{
    node<Type> *temp;
    temp = head;
    cout << "Doubly linked list is \n";
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class Type>
int dllist<Type>::count()
{
    node<Type> *temp;
    int ct = 0;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        ct++;
    }
    return ct;
}

int main()
{
    dllist<int> l1, l2, l3;
    int x, del, choice, ct, pos;
    node<int> *find;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "\t \t *** MAIN MENU *** \n";
        cout << "1.Add to Head\n";
        cout << "2.Add at ith position\n";
        cout << "3.Add to Tail\n";
        cout << "4.Delete from ith position\n";
        cout << "5.Delete from Tail\n";
        cout << "6.Delete from Head\n";
        cout << "7.Find node\n";
        cout << "8.Delete node\n";
        cout << "9.Reverse\n";
        cout << "10.concatenate\n";
        cout << "11.operator+\n";
        cout << "12.count\n";
        cout<<" =============================="<<endl<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            x = l1.input();
            l1.addtohead(x);
            l1.display();
            break;
        case 2:
            x = l1.input();
            cout << "Enter the position at which element is to be added\n";
            cin >> pos;
            l1.add_at_i(x, pos);
            l1.display();
            break;
        case 3:
            x = l1.input();
            l1.addtotail(x);
            l1.display();
            break;
        case 4:
            cout << "Enter the position at which element is to be deleted\n";
            cin >> pos;
            del = l1.remove_at_i(pos);
            cout << del << " has been deleted\n";
            l1.display();
            break;
        case 5:
            if (!l1.isempty())
            {
                del = l1.deletefromtail();
                cout << del << " has been deleted\n";
                l1.display();
            }
            else
                cout << "List is empty\n";
            break;
        case 6:
            if (!l1.isempty())
            {
                del = l1.deletefromhead();
                cout << del << " has been deleted\n";
                l1.display();
            }
            else
                cout << "List is empty\n";
            break;
        case 7:
            if (!l1.isempty())
            {
                cout << "Enter the value to find the node\n";
                cin >> x;
                find = l1.isinlist(x);
                if (find != NULL)
                    cout << find->info << " Node is found\n";
                else
                    cout << "Node not found\n";
            }
            else
            {
                cout << "List is empty\n";
            }
            break;
        case 8:
            if (!l1.isempty())
            {
                cout << "Enter the value to be deleted\n";
                cin >> x;
                l1.deletenode(x);
                l1.display();
            }
            else
                cout << "List is empty\n";
            break;
        case 9:
            if (!l1.isempty())
            {
                l2.reverse(l1);
            }
            else
                cout << "List is empty\n";
            break;
        case 10:
            if ((l1.isempty()) && (l2.isempty()))
                cout << "List is empty\n";
            else
            {
                l2.concat(l1);
                cout << "Concatenated list is \n";
                l2.display();
            }
            break;
        case 11:
            l3 = l1 + l2;
            l3.display();
            break;
        case 12:
            ct = l1.count();
            cout << "Linked list have " << ct << " nodes\n";
            break;
        default:
            cout << "Error in input\n";
            break;
        }
        cout << "Do you want to continue\n";
        cin >> ch;
    }
    return 0;
}
