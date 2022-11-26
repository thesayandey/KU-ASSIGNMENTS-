#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int binarySearchIterative(int arr[], int low, int high, int key){
   int mid;
    while(low<high){
        mid = (low+high)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key){
    int mid;
    if(low>high){
        return -1;
    }
    else{
        mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            return binarySearchRecursive(arr,low,mid-1,key);
        }
        else{
            return binarySearchRecursive(arr,mid+1,high,key);
        }
    }
}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int menu(int arr[], int n, int key, int low, int high){
    int ch;

    cout<<"Choose an option.......\n";
    cout<<"OPTION 1: Search using linear search\n";
    cout<<"OPTION 2: Search using Iterative binary search\n";
    cout<<"OPTION 3: Search using recursive binary search\n";

    cin>>ch;
    int ans;
     switch(ch){
        case 1:
            ans = linearSearch(arr,n,key);
            break;
        case 2:
            ans = binarySearchIterative(arr,low,high,key);
            break;
        case 3:
            ans = binarySearchRecursive(arr,low,high,key);
            break;
    }

    return ans;
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

    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    cout<<endl;

    int ans;
    int low = 0;
    int high = n-1;
    ans = menu(arr,n,key,low,high);

    cout<<endl;
    if(ans == -1){
        cout<<"Opps! Element not found..."<<endl;
    }
    else{
        cout<<"Element found at index: "<<ans<<" "<<endl;
    }

    return 0;
}