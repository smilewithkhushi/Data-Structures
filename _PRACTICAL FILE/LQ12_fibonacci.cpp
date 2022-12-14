#include <iostream>
using namespace std;

int fibonacci_numbers_rec(int n)
{
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else{
		return fibonacci_numbers_rec(n-2) + fibonacci_numbers_rec(n-1);
	}
}


void fibonacci_numbers(int n)
{
    int f1 = 0, f2 = 1, i;
 
    if (n < 1)
        return;
    cout << f1 << " ";
    for (i = 1; i < n; i++) {
        cout << f2 << " ";
        int next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    return ;
}
 
int main() {
	int n;
    cout<<"\n - > Enter the terms of fibonacci series : ";
    cin>>n;
    
    cout<<endl<<"\t ~~ using recursion ~~ "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout << fibonacci_numbers_rec(i) << " ";
	}

    
    cout<<"\n \t ~~ using iteration ~~ "<<endl;

	fibonacci_numbers(n);
    
	return 0;
}
// This code is contributed by Rupesh Kapse
