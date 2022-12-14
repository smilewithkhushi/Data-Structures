#include <iostream>
using namespace std;

//using recursion
unsigned int factorialrec(unsigned int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorialrec(n - 1);
}

//using iteration
unsigned int factorial(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
	int num;
    cout<<"-> Enter the number : ";
    cin>>num;
    
	cout << "\n ~~ USING RECURSION ~~ \n ->Factorial of "
		<< num << " is " << factorialrec(num) << endl;

    cout << "\n ~~ USING ITERATION ~~ \n ->Factorial of "
		<< num << " is " << factorial(num) << endl;


	return 0;
}
