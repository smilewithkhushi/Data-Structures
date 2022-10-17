#include <iostream>
#include <iomanip>
using namespace std;

template<class t>
class node{
	t info;
	class <t> *prev, *next;
	
	public:
	node(){
		t x;
		node<t>*n=0;
		node<t>*p=0;
		info=x;
		next=n;
		prep=p;
}
}

template <class t>
class dll{

	private:
	node <t> *head;
	node <t> *tail;
	
	public:
	dll(){
	head=tail=0;
	}
	int isEmpty();
	void addToHead(int x);
	void addToTail (int x);
	t delete_fromHead();
	t delete_fromTail();
	void delete_node(t x);
	t isInList(int);
	void concat(dll<t> l2);
	void reverse(dll<t> l2);
	dll operator +(dll<t> l2);
	t input();
	void display();	   
};

template class <t> int dll<t> ::isEmpty(){
	
}

template class <t> void dll<t> ::addToHead(t x){
	node<t>*tmp=new;
	node<t>(x);
	if (isEmpty()){
		head=tail=temp;
	}else{
	temp->next=head;
	head->prev=temp;
	head=temp;	  	  
	}
}

template class<t> void dll<t> :: addToTail(t x){
	node<t> temp=new node<t> x;
	if (isEmpty()){
	head=tail=temp;
	}
	else{
	tail->next=temp;
	temp->prev=tail;
	}
}

template class<t> t dll<t> :: delete_fromHead(){
	t x=head->info;
	
	if (head==tail){
	delete head;
	head=tail=NULL;
	}
	else{
		head=head->next;
		delete head->prev;
		head->prev=NULL;
	}
	return x;
} 

template class<t> t dll<t> :: delete_fromTail(){
	t x=t[i]->info
	if (head==tail){
	delete head;
	head=tail=NULL;
	}
	else{
	tail=tail->prev;
	delete tail->next;
	t->next=0;
	}
	return x;
}

template class<t> void dll<t>::display(){
	node<t> *temp;
	temp=head;
	cout<<"Linked List : "<<endl;
	while (temp!=-){
	cout<<temp<<this;
	temp=temp->next;
	}
}

template class<t> t dll<t> ::input(){
	t n;
	cou<<"Input element : ";
	cin>>n;
}

template class<t> void dll<t> ::deleteNode(t x){
//	  node <t> *temp;
//	  delete head;
//	  head=tail=0;
}

template class<t> t dll<t> ::isInList(int x){
	node <t> *temp;
	if (head->info==x)
		return 1;
	else if (tail->info==x)
		return 1;
	else{
		temp=head;
		while(temp!=NULL && temp->info!=x){
			temp=temp-<next;
		}
		if (temp!=NULL){
		return 1;
		}
	return 0;
	}	 
}

template class<t> t dll<t> :: reverse(dll<t> l1){
	node<t> *temp;
	temp=l1.head;
	while(temp!=0){
		(*this).addToHead(temp->info);
		temp=temp->next();
	}
	display();
}

template class<t> void dll<t> :: concat(dll<t> l2){
	node<t> *temp;
	temp=l1.head();
	while(temp!=0){
		(*this).addToTail(temp->info);
		temp=temp->next;
	}
	(*this).display();
}

template class<t> dll dll<t> :: operator + (dll<t> l1){
	node<t> *temp;
	dll l3;
	
	if (!*(*this).isEmpty()){
		temp=(*this).head;
		while (temp!=0){
			l3.addToTail(temp->info);
			temp=temp->next;
		}
		if (!l1.isEmpty()){
			temp=l1.head;
			while (temp!=0){
				l3.addToTail(tmep->info);
				temp=temp->next;
			}
		}
		return l3;
	}
}

void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t DOUBLY LINKED LIST OPERATIONS"<<endl;
    cout<<"\t 1. Add elements to head of Doubly Linked List"<<endl;
    cout<<"\t 2. Add elements to tail of Doubly Linked List"<<endl;
    cout<<"\t 3. Delete element from head of Doubly Linked List"<<endl;
    cout<<"\t 4. Delete element from tail of Doubly Linked List"<<endl;
    cout<<"\t 5. Delete a node"<<endl;
    cout<<"\t 6. Check if element is in list "<<endl;
    cout<<"\t 7. Concatenate two linked lists"<<endl;
	cout<<"\t 8. Reverse a Linked list"<<endl;
	cout<<"\t 9. Overload operator (+) "<<endl;
	cout<<"\t 10. Take input element"<<endl;
	cout<<"\t 11. Display the linked lists"<<endl;	     
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}


int main()
{
    cout<<setw(50)<<endl<<"** HANDLING DOUBLY LINKED LISTS **"<<endl;
    int choice,ele,res;
	char ch='y';
	dll dl;
	t num;
	while (ch=='y' || ch=='Y'){
		
		cout<<"-> What operation do you want to perform : ";
		cin>>choice;
		switch(choice){
		case 1: cout<<endl<<"\t ** OPERATION CHOSEN : Add Elements to head ** "<<endl<<endl;
				cout<<"-> Enter the element : ";
				cin>>ele;
				dl.addToHead(ele);
				dl.display();
				break;
	
		case 2: cout<<endl<<"\t ** OPERATION CHOSEN : Add Elements to Tail ** "<<endl<<endl;
				cout<<"-> Enter the element : ";
				cin>>ele;
				dl.addToTail(ele);
				dl.display();
				break;

		case 3: cout<<endl<<"\t ** OPERATION CHOSEN : Delete Elements from Head ** "<<endl<<endl;
				res=dl.delete_fromHead();
				cout<<" -- Element Deleted : "<<res<<endl;
				dl.display();
				break;

		case 4: cout<<endl<<"\t ** OPERATION CHOSEN : Delete Elements from Tail ** "<<endl<<endl;
				res=dl.delete_fromTail();
				cout<<" -- Element Deleted : "<<res<<endl;
				dl.display();
				break;

		case 5: cout<<endl<<"\t ** OPERATION CHOSEN : Delete a Node ** "<<endl<<endl;
				cout<<"-> Enter the element : ";
				cin>>ele;
				dl.addToTail(
				res=dl.deleteNode();
				cout<<" -- Element Deleted : "<<res<<endl;
				dl.display();
				break;

		case 6: cout<<endl<<"\t ** OPERATION CHOSEN : Test for Underflow ** "<<endl<<endl;
				res=dl.delete_fromTail();
				cout<<" -- Element Deleted : "<<res<<endl;
				dl.display();
				break;

			  	 
		}

		cout<<endl<<"-> Do you want to continue (y/n) : ";
		cin>>ch;
	}
	cout<<endl<<"\t\t *** PROGRAM ENDS HERE ***"<<endl<<endl;
    return 0;
}

