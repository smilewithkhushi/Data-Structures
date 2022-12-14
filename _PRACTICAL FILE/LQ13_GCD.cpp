#include <iostream>
using namespace std;

//iterative function
int gcd(int a, int b)
{
	int result = min(a, b); // Find Minimum of a nd b
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	return result; // return gcd of a nd b
}

int gcd_rec(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd_rec(a-b, b);
    return gcd_rec(a, b-a);
}

int main()
{
	int a, b;
    cout<<"\n -> Enter the first number : ";
    cin>>a;
    cout<<"\n -> Enter the second number : ";
    cin>>b;


    cout<<"\t ~~ RECURSIVE RESULT ~~"<<endl;
    cout << "GCD of " << a << " and " << b << " is "
		<< gcd_rec(a, b);
    cout<<"\n \t ~~ ITERATIVE RESULT ~~"<<endl;
	cout << "GCD of " << a << " and " << b << " is "
		<< gcd(a, b);
	return 0;
}
