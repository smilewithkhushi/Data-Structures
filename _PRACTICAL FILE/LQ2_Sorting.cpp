#include<iostream>
using namespace std;

const int size=50;
class sorting{
	int arr[size];		//array for sorting
	int n;				//size of array

	public:
	void getData();
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	void display();
};

void sorting::getData(){
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
void sorting::insertionSort(){
    for (int i=0; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}
void sorting::selectionSort(){
    int temp;
    for (int i=0; i<n; i++){
        int min=i;
        for (int j=min+1; j<n; j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }
    if (i!=min){
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    }
}

void sorting::bubbleSort(){
    int temp;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void sorting:: display(){
    for (int i=0; i<n; i++){
        cout<<"\t"<<arr[i];
    }
    cout<<endl;
}
void operationList(){
	cout<<endl;
	cout<<"\t ****************************"<<endl;
	cout<<"\t SORTING ON ARRAY "<<endl;
	cout<<"\t1.  Bubble Sort "<<endl;
	cout<<"\t2.  Insertion Sort "<<endl;
	cout<<"\t3.  Selection Sort "<<endl;
	cout<<"\t ****************************"<<endl;
	cout<<endl;
	return ;
}
int main(){
	sorting ob;
	char ch='y';
	int result, ele;
	int choice;
	do{
		operationList();
		cout<<endl<<"-> Select the sort you want to perform : ";
		cin>>choice;
		cout<<endl;
		switch(choice){
		case 1: ob.getData();
    			cout<<"\n-> Array before sorting : ";
                ob.display();
				ob.bubbleSort();
				cout<<"\n-> Array after BUBBLE SORT : ";
				ob.display();
				break;

		case 2: ob.getData();
                cout<<"-> Array before sorting : ";
                ob.display();
				ob.insertionSort();
				cout<<"\n-> Array after INSERTION SORT : ";
				ob.display();
				break;

		case 3: ob.getData();
                cout<<"\n-> Array before sorting : ";
				ob.display();
				ob.selectionSort();
				cout<<"\n-> Array after SELECTION SORT : ";
				ob.display();
				break;

		default: cout<<"\t !! INVALID CHOICE !!"<<endl<<endl;

		}
		cout<<endl<<"Do you want to continue (y/n)? ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	cout<<endl<<endl<<"\t PROGRAM ENDS HERE! "<<endl;
	return 0;

}

