#include<iostream>
using namespace std;

const int size=50;
class search{
	int arr[size];		//array for searching
	int n;				//size of array

	public:
   	int key;			//search element
	void getData();
	int linearSearch();
	int binarySearch();
	void display(int);
};

void search::getData(){
	cout<<"\n -> Enter the number of elements you want to enter : ";
	cin>>n;
	if (n<=100){
		cout<<endl<<"-> Input "<<n<<" elements : ";
		for (int i=0; i<n; i++){
			cin>>arr[i];
		}
	}else{
		cout<<endl<<"\t !! INVALID INPUT , try again !!"<<endl;
		getData();
	}
	return ;
}//input the array for search operation

int search::linearSearch(){
	cout<<endl<<"\t _ PERFORMING LINEAR SEARCH _"<<endl;
	for (int i=0; i<n; i++){
		if (key==arr[i]){
			return i;
		}
	}
	return -1;
}//linear search function

int search::binarySearch(){
	cout<<endl<<"\t _ PERFORMING BINARY SEARCH _"<<endl;
	cout<<endl<<"\t _ PERFORMING BINARY SEARCH _"<<endl;
	int low=0;
	int high=n-1;

    while (low <= high){
        int mid = low + (high - low)/2;

        if (arr[mid] == key)        return mid;
        else if (arr[mid] < key)     low = mid + 1;
        else           high = mid - 1;
    }
    return -1;
}//Binary search function

void search::display(int result){
	if (result>=0){
		cout<<endl<<"~~ The element has been found at "<<result<<" index!"<<endl<<endl;
	}else{
		cout<<endl<<"~~ Search Unsuccessful! "<<endl<<endl;
	}
	return;
}// displaying the search result function

void operationList(){
	cout<<endl;
	cout<<"\t ****************************"<<endl;
	cout<<"\t SEARCH OPERATIONS ON ARRAY "<<endl;
	cout<<"\t1.  Linear Search "<<endl;
	cout<<"\t2.  Binary Search "<<endl;
	cout<<"\t ****************************"<<endl;
	cout<<endl;
	return ;
}
int main(){
	search ob;
	char ch='y';
	int result, ele;
	int choice;
	do{
		operationList();
		cout<<endl<<"-> Select the Operation you want to perform : ";
		cin>>choice;
		cout<<endl;
		switch(choice){
		case 1: ob.getData();
				cout<<"-> Enter the element you want to search : ";
				cin>>ele;
				ob.key=ele;
				result=ob.linearSearch();
				ob.display(result);
				break;

		case 2: ob.getData();
				cout<<"-> Enter the element you want to search : ";
				cin>>ob.key;
				result=ob.binarySearch();
				ob.display(result);
				break;
		default: cout<<"\t !! INVALID CHOICE !!"<<endl<<endl;
		}
		cout<<"Do you want to continue (y/n)?";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	cout<<endl<<endl<<"\t PROGRAM ENDS HERE! "<<endl;
	return 0;

}

