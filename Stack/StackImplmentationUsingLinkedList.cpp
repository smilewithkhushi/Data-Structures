//implementing stacks using linked lists : "->" is used to refer to the member belonging to the struct "node" type objects.

#include<iostream>
#include <iomanip>
using namespace std;

struct node
{
    int info;
    node*next;
};
class stackType
{
    node *top;
public:
    stackType()
    {
        top=NULL;
    }
    void push(node *);
    int pop();
    int isempty();
    int display();
    node *createnode(int);
};
int stackType::isempty()
{
    if (top==NULL)  return 1;
    else return -1;

}
node *stackType::createnode(int x){
    node *temp;
    temp=new(node);
    temp->info=x;
    temp->next=NULL;
    return temp;
}
void stackType::push(node *temp){
    if (top==NULL){
        top=temp;
    }else{
    temp->next=top;
    top=temp;
    }
}
int stackType::display()
{
    if(top==NULL)   cout<<"-> Stack is empty! "<<endl;
    else{
        cout<<"-> Contents of stack from top most node are : ";
        for (node* temp=top; temp!=NULL ; temp=temp->next){
            cout<<temp->info<<" , ";
        }
    }
}
int stackType::pop(){
    node *temp;
    if (top->next==NULL){
        temp=top;
        top=NULL;
        return temp->info;
        delete temp;
    }
    else{
        temp=top;
        top=top->next;
        return temp->info;
        delete temp;
    }
}

void menu(){
	cout<<setw(30)<<"======================="<<endl;
	cout<<"\t\t STACK OPERATIONS"<<endl;
	cout<<"\t 1. PUSH the element into stack"<<endl;
	cout<<"\t 2. POP the element from stack"<<endl;
	cout<<"\t 3. DISPLAY the elements of stack"<<endl;
	cout<<"\t 4. Check if stack is empty"<<endl;
	cout<<setw(30)<<"\t======================="<<endl<<endl;
	return;
}

int main()
{
    int choice, ele, val;
    char ch='y';
    node *temp1;
    stackType st;
    do{
        menu();
        cout<<"-> Select the operation you want to perform : ";
        cin>>choice;
        switch(choice){
        case 1: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : PUSH the elements ** "<<endl;
            cout<<"-> Enter a value : ";
            cin>>val;
            temp1=st.createnode(val);
            if (temp1!=NULL){
            st.push(temp1);
            st.display();
        }else{
        cout<<"\n Compile out of memory";
        }
            break;

        case 2: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : POP the elements ** "<<endl;
            ele=st.pop();
            cout<<"-> Element Popped : "<<ele<<endl;
            break;

        case 3: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : DISPLAY the elements ** "<<endl;
            st.display();
            break;
        case 4: cout<<endl<<setw(40)<<" ** OPERATION CHOOSEN : Check emptiness ** "<<endl;
            ele=st.isempty();
            if (ele==1)     cout<<endl<<"-> The Stack is Empty! "<<endl;
            else cout<<endl<<"-> The Stack is not Empty! "<<endl;
            break;
        default : cout<<endl<<"!! Select a valid operation !!"<<endl<<endl;
        }

        cout<<endl<<endl<<"-> Do you want to continue (y/n)?";
        cin>>ch;
    }while(ch=='y' || ch=='Y');

}
