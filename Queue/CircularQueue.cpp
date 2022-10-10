#include <iostream>
#include <iomanip>
using namespace std;

void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t CIRCULAR QUEUE OPERATIONS"<<endl;
    cout<<"\t 1. Add elements into Queue"<<endl;
    cout<<"\t 2. Delete element from Queue"<<endl;
    cout<<"\t 3. Display the elements of the queue"<<endl;
    cout<<"\t 4. Check if Queue is empty"<<endl;
    cout<<"\t 5. Check if Queue is full"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}

const int size=5;
class queuetype{
	int Q[size];
	int f, r;  //front and rear

	public:
	void addition(int a);
	int deletion();
	int isFull();
	int isEmpty();
	void display();

	queuetype(){
		f=r=-1;
	}
};

void queuetype::addition(int a){
	int op=isEmpty();
	if (op==1){
		f=r=0;
		Q[r]=a;
	}//queue is empty
	else if (r==size-1){
		r=0;
		Q[r]=a;
	}else{
		r++;
		Q[r]=a;
	}
}

int queuetype::deletion(){
	int rem;
	if (f==r){
		rem=Q[f];
		f=r=-1;
	}else if (f=size-1){
		rem=Q[f];
		f=0;
	}
	else{
		rem=Q[f];
		f++;
	}
	return rem;
}

int queuetype:: isEmpty(){
	int e;
	if (f==-1){
		return 1;
	}else{
		return -1;
	}
}
int queuetype::isFull(){
	if ((f==r+1)|| (f==0) && (r==size-1)){
		return 1;
	}else{
		return -1;
	}
}
void queuetype::display(){
 	cout<<endl<<"-> Displaying the Queue : "<<endl;
	for (int i=0; i<=r; i++){
		if (i>=f){
		cout<<setw(3)<<Q[i];
		}else{
			cout<<setw(4)<<"___";
		}
	}
	for (int i=r+1; i<size; i++){
		cout<<setw(4)<<"___";
	}
	cout<<endl<<endl;
}

int main()
{
    cout<<setw(50)<<endl<<"** QUEUE IMPLEMENTATION USING ARRAY **"<<endl;
    int choice,ele,res;
	char ch='y';
	queuetype queue;
	operationList();
	while (ch=='y' || ch=='Y'){
		
		cout<<"-> What operation do you want to perform : ";
		cin>>choice;
		switch(choice){
		case 1: cout<<endl<<"\t ** OPERATION CHOSEN : Enter Elements ** "<<endl<<endl;
				cout<<"-> Enter the element in the queue : ";
				cin>>ele;
				queue.addition(ele);
				queue.display();
				break;

		case 2: cout<<endl<<"\t ** OPERATION CHOSEN : Delete Elements ** "<<endl<<endl;
				res=queue.deletion();
				cout<<" -- Element Deleted : "<<res<<endl;
				queue.display();
				break;
		case 3: cout<<endl<<"\t ** OPERATION CHOSEN : Display Circular Queue ** "<<endl<<endl;
				queue.display();
				break;
		case 4: cout<<endl<<"\t ** OPERATION CHOSEN : Checking for Underflow ** "<<endl<<endl;
				res=queue.isEmpty();
				if (res==1)	cout<<"Queue is Empty! "<<endl;
				else cout<<"Queue is not Empty! " <<endl;
				queue.display();
				break;

		case 5: cout<<endl<<"\t ** OPERATION CHOSEN : Checking for Overflow ** "<<endl<<endl;
				res=queue.isFull();
				if (res==1)	cout<<"Queue is Full! "<<endl;
				else cout<<"Queue is not Full! " <<endl;
				queue.display();
				break;
		}

		cout<<endl<<"-> Do you want to continue (y/n) : ";
		cin>>ch;
	}
	cout<<endl<<"\t\t *** PROGRAM ENDS HERE ***"<<endl<<endl;
    return 0;
}

