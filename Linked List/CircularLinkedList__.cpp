#include <iostream>
#include <iomanip>
using namespace std;

tempate<class Type>
class cnode
{
public:
    Type info;
	cnode* next;
	cnode(Type x, cnode* n=0){
		info =x;
		next= n;
	}
};

template<class Type>
class cllist
{
 
public:
	cnode<Type>* cursor;
	clist(){
	cursor=NULL;}    
	void input();
	int isempty(){
		if (cursor==NULL)
			return 1;
		else
			return 0;
	}

	void addtofront(Type x);
	void addtoback(Type x);
	void addafter(Type x, Type y);
	void add_at_i(Type x);
	Type deletefromfront ();
	Type deletefromback();
	int count();
	cnode<Type>* isinlist(Type x);
	cllist operator+ <cllist<Type> l1);
	void display();
	};

template<class Type>
void cllist<Type<::input(){
	int n;
	Type x;
	cout<<"-> Enter the no. of nodes in the Circular linked list : \n";
	cin>>n;
	for (int i=0; i<n; i++){
		cout<<"Enter the info part of node " <<i+1<<" : ";
		cin>>x;
		addtoback(x);
	}
}

template<class Type> 
void cllist<Type>::addtofront(Type x){
	cnode<Type>* temp= node cnode<Type>(x);
	if (isempty(){
	cursor=temp;
	temp-> next=cursor;
	}else{
	temp-> next=cursor-> next;
	cursor-> next =temp;
	}
}


void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t CIRCULAR LINKED LIST OPERATIONS"<<endl;
    cout<<"\t 1. Add new element in Linked List"<<endl;
    cout<<"\t 2. Add new element into Linked List"<<endl;
    cout<<"\t 3. Delete element from Linked List"<<endl;
    cout<<"\t 4. Count the number of elements in Linked List"<<endl;
    cout<<"\t 5. Display the Linked List"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}

int main()
{
    cout<<setw(50)<<endl<<"** IMPLEMENTATION OF CIRCULAR LINKED LIST **"<<endl;
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
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Add the new element ** "<<endl;
            cout<<"-> Enter the element : ";
            cin>>ele;
            node* tmp=list.createNewNode(ele);
            list.add(tmp);
            list.display();
            break;
        }
        case 2:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Delete the element ** "<<endl;
            list.remove();
            list.display();
            break;
        }
        case 3:
        {
            cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Count number of elements from list ** "<<endl;
            res=list.count();
            cout<<"-> Number of elements in list are : "<<res<<endl;
            list.display();
            break;
        }
        case 4:
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

