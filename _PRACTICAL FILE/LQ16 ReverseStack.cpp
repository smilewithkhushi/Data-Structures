#include <iostream>
using namespace std;

class stacktype{
    int top=-1;
    int size;
    int arr[10];

    public:
    void push(int ele){
        arr[++top]=ele;
    }

    int pop(){
        int ele=arr[top];
        top--;
        return ele;
    }
    void display(){
        for (int i=0; i<=top; i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
    void reverse(stacktype &s2);
    stacktype(int n){
        size=n;
        arr[size];
    }
};

void stacktype::reverse(stacktype &s2){
        int num;
        do{
            num=pop();
            s2.push(num);
        }while(top>=0);
}
int main()
{
    cout << endl<<" \t ** REVERSE THE STACK USING ANOTHER STACK ** " <<endl<< endl;
    int num, ele;
    cout<<"-> Enter the size of the stack : ";
    cin>>num;

    stacktype stack1(num);
    stacktype rev(num);

    cout<<endl<<"-> PUSHING THE ELEMENTS IN STACK "<<endl;
    for (int i=0; i<num; i++){
        cout<<"Enter element : ";
        cin>>ele;
        stack1.push(ele);
    }
    cout<<endl<<"-> THE CONTENTS OF STACK BEFORE REVERSAL "<<endl;
    stack1.display();
    cout<<endl<<"-> The Contents of stack after reversal "<<endl;
    stack1.reverse(rev);
    rev.display();

    return 0;
}
