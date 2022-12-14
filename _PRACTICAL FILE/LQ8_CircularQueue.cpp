#include <iostream>
#include <iomanip>
using namespace std;

void operationList()
{
	cout << endl
		 << endl;
	cout << setw(40) << "=======================" << endl;
	cout << "\t \t CIRCULAR QUEUE OPERATIONS" << endl;
	cout << "\t 1. Add elements into Queue" << endl;
	cout << "\t 2. Delete element from Queue" << endl;
	cout << "\t 3. Display the elements of the queue" << endl;
	cout << "\t 4. Check if Queue is empty" << endl;
	cout << "\t 5. Check if Queue is full" << endl;
	cout << setw(40) << "=======================" << endl
		 << endl;
	return;
}

#include <iostream>
using namespace std;
const int MAX = 5;
template <class Type>
class Queuetype
{
	int f, r;

public:
	Type q[MAX];
	Queuetype()
	{
		f = r = -1;
	}
	void addition(Type);
	Type deletion();
	int isempty();
	int isfull();
	void display();
	int count();
};
template <class Type>
void Queuetype<Type>::addition(Type x)
{
	if (f == -1)
	{
		f = r = 0;
		q[r] = x;
	}
	else
	{
		r++;
		q[r] = x;
	}
}
template <class Type>
int Queuetype<Type>::isempty()
{
	if (f == -1)
		return 1;
	else
		return -1;
}
template <class Type>
int Queuetype<Type>::isfull()
{
	if (r == MAX - 1)
		return 1;
	else
		return -1;
}
template <class Type>
Type Queuetype<Type>::deletion()
{
	Type temp;
	if (f == r)
	{
		temp = q[f];
		f = r = -1;
	}
	else
	{
		temp = q[f];
		f++;
	}
	return temp;
}
template <class Type>
int Queuetype<Type>::count()
{
	int ct = 0;
	if (f == -1)
		return 0;
	else
	{
		for (int i = f; i <= r; i++)
		{
			ct++;
		}
		return ct;
	}
}
template <class Type>
void Queuetype<Type>::display()
{
	if (f == -1)
	{
		cout << "Queue is empty\n";
	}
	else
	{
		cout << "Queue is => ";
		for (int i = f; i <= r; i++)
		{
			cout << q[i] << " ";
		}
	}
}

int main()
{
	cout << setw(50) << endl
		 << "** QUEUE IMPLEMENTATION USING CIRCULAR ARRAY **" << endl;
	int choice, ele, res;
	char ch = 'y';
	Queuetype<int> queue;
	operationList();
	while (ch == 'y' || ch == 'Y')
	{

		cout << "-> What operation do you want to perform : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl
				 << "\t ** OPERATION CHOSEN : Enter Elements ** " << endl
				 << endl;
			cout << "-> Enter the element in the queue : ";
			cin >> ele;
			queue.addition(ele);
			queue.display();
			break;

		case 2:
			cout << endl
				 << "\t ** OPERATION CHOSEN : Delete Elements ** " << endl
				 << endl;
			res = queue.deletion();
			cout << " -- Element Deleted : " << res << endl;
			queue.display();
			break;
		case 3:
			cout << endl
				 << "\t ** OPERATION CHOSEN : Display Circular Queue ** " << endl
				 << endl;
			queue.display();
			break;
		case 4:
			cout << endl
				 << "\t ** OPERATION CHOSEN : Checking for Underflow ** " << endl
				 << endl;
			res = queue.isempty();
			if (res == 1)
				cout << "Queue is Empty! " << endl;
			else
				cout << "Queue is not Empty! " << endl;
			queue.display();
			break;

		case 5:
			cout << endl
				 << "\t ** OPERATION CHOSEN : Checking for Overflow ** " << endl
				 << endl;
			res = queue.isfull();
			if (res == 1)
				cout << "Queue is Full! " << endl;
			else
				cout << "Queue is not Full! " << endl;
			queue.display();
			break;
		}

		cout << endl
			 << "-> Do you want to continue (y/n) : ";
		cin >> ch;
	}
	cout << endl
		 << "\t\t *** PROGRAM ENDS HERE ***" << endl
		 << endl;
	return 0;
}
