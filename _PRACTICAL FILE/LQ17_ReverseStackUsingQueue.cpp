#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    int n;   //Number of elements to take as input from the user.
    cin>>n;

    stack<int> s;
    queue<int> q;
    int data;
    //Enter the elements.
    for(int i=0;i<n;i++){
        cin>>data;
        s.push(data);
    }

    //Push the element into the queue from the stack and print the element to denote how they are being stored in the stack.

    cout<<"Elements before reversing the stack:"<<endl;
    while(s.size()!=0){
        int ele=s.top();
        cout<<ele<<" ";
        q.push(ele);
        s.pop();
     }
     cout<<endl;

     //Push the element into the stack from the queue.

     while(q.size()!=0){
         int ele=q.front();
         s.push(ele);
         q.pop();
     }

     cout<<"Elements after reversing the stack:"<<endl;
     while(s.size()!=0){
         cout<<s.top()<<" ";
         s.pop();
     }
     cout<<endl;
}