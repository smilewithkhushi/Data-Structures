//IMPLEMENTING STACK USING TEMPLATES

#include<iostream>
#include<iomanip>
using namespace std;

const int MAX=5;

template <class t>
class stacktype
{
    int top;

    t arr[MAX];
    
public :
    stacktype()
    {
        top=-1;
    }

    void push();
    t pop();
    void display();
    int isEmpty();
    int isFull();
};

template <class t> void stacktype<t>::push(){
    t ele;
    cout<<"Enter the element : ";
    cin>>ele;
    ++top;
    arr[top]=ele;
}

template <class t> t stacktype<t>::pop()
{
    t ele=arr[top];
    --top;
    return ele;
}

template <class t> int stacktype<t>:: isEmpty()
{
    int flag;
    if (top==-1)	flag=1;
    else 			flag=0;
    return flag;
}

template <class t> int stacktype<t> ::isFull()
{
    int flag;
    if (top==MAX-1)	   flag=1;
    else 			flag=0;
    return flag;
}

template <class t> void stacktype<t>::display()
{
    cout<<"-> DISPLAYING THE ARRAY : "<<endl<<endl;
    for (int i=top; i>=0; i--)
    {
        cout<<arr[i]<<"\t";
    }
    return;
}

template <class t> void stackOperation(stacktype<t> obj){
int choice,ele, num,res,sizeArr;
    char ch='y';
	while(ch=='y' || ch=='Y')
    {
        cout<<"--> Which operation do you want to perform :";
        cin>>choice;
    	cout<<endl;
        switch(choice)
        {
        case 1:
            cout<<"\t OPERATION CHOOSEN :: PUSH "<<endl<<endl;
            res=obj.isFull();
            if (res==1) cout<<"Error : Stack is full, Cannot push elements!"<<endl<<endl;
            else
            {
               obj.push();
            }
            break;
        case 2:
            cout<<"\t OPERATION CHOOSEN :: POP"<<endl<<endl;
            res=obj.isEmpty();
            if (res==1) cout<<"Error : Stack is empty, Cannot pop elements!"<<endl<<endl;
            else
            {
                cout<<setw(3)<<obj.pop();

            }
            break;

        case 3:
            cout<<"\t OPERATION CHOOSEN :: DISPLAY"<<endl<<endl;
            obj.display();
            break;

        case 4:
            cout<<"\t OPERATION CHOOSEN :: isEmpty "<<endl<<endl;
            res=obj.isEmpty();
            if (res==1) cout<<"The stack is Empty"<<endl;
            else cout<<"The stack is not Empty"<<endl;
            break;

        case 5:
            cout<<"\t OPERATION CHOOSEN :: isFull"<<endl<<endl;
            res=obj.isFull();
            if (res==1) cout<<"The stack is full"<<endl;
            else cout<<"The stack is not full"<<endl;
            break;
        default :
            cout<<"\t Enter a valid choice!"<<endl;
        }
        cout<<"\n\n Do you want to continue? (y/n) :";
        cin>>ch;
        cout<<endl;

    }
    cout<<setw(20)<<"PROGRAM ENDS HERE"<<endl;

return ;

}

void operationList()
{
    cout<<endl<<endl;
    cout<<setw(40)<<"======================="<<endl;
    cout<<"\t \t STACK OPERATIONS"<<endl;
    cout<<"\t 1. PUSH the element into stack"<<endl;
    cout<<"\t 2. POP the element from stack"<<endl;
    cout<<"\t 3. DISPLAY the elements of stack"<<endl;
    cout<<"\t 4. Check if stack is empty"<<endl;
    cout<<"\t 5. Check if stack is full"<<endl;
    cout<<setw(40)<<"======================="<<endl<<endl;
    return;
}
int main()
{
    cout<<setw(50)<<endl<<"** STACK IMPLEMENTATION USING ARRAY **"<<endl<<endl;

    int choice,ele, num,res,sizeArr;
	stacktype<int> s1;
    stacktype<string> s2;
	stacktype<float> s3;

	string st_type;
	cout<<"\n-> Which type of stack do you want to create (int/string/float)? : ";
	cin>>st_type;
	operationList();

	if (st_type=="int" || st_type=="INT"){
		stackOperation(s1);
	}else if (st_type=="float" || st_type=="FLOAT"){
		stackOperation(s3);
	}else if (st_type=="string" || st_type=="STRING"){
		stackOperation(s2);
	} else{
		cout<<endl<<"!! INVALID CHOICE : INTEGER STACK HAS BEEN CHOOSEN BY DEFAULT"<<endl<<endl;
		stackOperation(s1);
	}

    return 0;
}

