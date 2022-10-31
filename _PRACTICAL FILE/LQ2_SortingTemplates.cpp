#include<iostream>
using namespace std;

const int size=50;
template<class t>
class sorting{
	t arr[size];		//array for sorting
	int n;				//size of array

	public:
	void getData();
	void bubbleSort();
	void insertionSort();
	void selectionSort();
	void display();
};

template<class t>
void sorting<t>::getData(){
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
}//input the array for sorting operation

template<class t>
void sorting<t>::insertionSort(){
    for (int i=0; i<n; i++){
        t key=arr[i];
        int j=i-1;
        while (j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}

template<class t>
void sorting<t>::selectionSort(){
    t temp;
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

template<class t>
void sorting<t>::bubbleSort(){
    t temp;
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
template<class t>
void sorting<t>:: display(){
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

template<class t>
void operation(sorting<t> ob){
        int choice;
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
}

int main(){
    cout<<"\n\t ** SORTING ON ARRAY ** "<<endl;
	char ch='y';
	int choice;
	do{
        string type;
        cout<<"\n-> Which type of array do you want to create (int/string/float)? : ";
        cin>>type;
        if (type=="int" || type=="INT"){
            sorting<int> ob1;
            operation(ob1);
        }
        else if (type=="string" || type=="STRING"){
            sorting<string> ob2;
            operation(ob2);
        }
        else if (type=="float" || type=="FLOAT"){
          sorting<float> ob3;
          operation(ob3);
        }
        else cout<<" ** INVALID CHOICE ** " <<endl;

		cout<<endl<<"Do you want to continue (y/n)? ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');

	cout<<endl<<endl<<"\t PROGRAM ENDS HERE! "<<endl;
	return 0;

}

