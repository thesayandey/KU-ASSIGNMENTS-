#include<bits/stdc++.h>
using namespace std;

//----------------------------INSERTION SORT--------------------------------

void insertionsort(int arr[], int n){
    cout<<"Running insertion sort.......\n";
    int key,j;
    for(int i=0;i<n;i++){
        key = arr[i];
        j = i-1;    //targetting the previous element of the key

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//---------------------------- SELECTION SORT------------------------------

void swap(int *m, int *n){
    int temp = *m;
    *m = *n;
    *n = temp;
}

void selectionsort(int arr[], int n){
    cout<<"Running selection sort.......\n";
    int min_index;

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min_index])
            min_index = j;
        }
        swap(&arr[i], &arr[min_index]);
    }
}

//-----------------------------BUBBLE SORT------------------------------------

void bubblesort(int arr[], int n){
    cout<<"Running bubble sort.......\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//------------------------ FUNCTION TO PRINT ARRAY-----------------------------

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void menu(int arr[], int n){
    cout<<"Choose an option.......\n";
    cout<<"OPTION 1: Sort using bubble sort\n";
    cout<<"OPTION 2: Sort using selection sort\n";
    cout<<"OPTION 3: Sort using insertion sort\n";
    
    int opt;
    cin>>opt;

    switch(opt){
        case 1:
            bubblesort(arr,n);
            break;
        case 2:
            selectionsort(arr,n);
            break;
        case 3:
            insertionsort(arr,n);
            break;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int *arr = new int(n);

    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<" th index: ";
        cin>>arr[i];
        cout<<endl;
    }

    cout<<"Array before sorting......."<<endl;
    printarray(arr,n);
    menu(arr,n);
    printarray(arr,n);

    return 0;
}