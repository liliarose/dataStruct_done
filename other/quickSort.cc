#include <iostream>

using namespace std;
 

void print (int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";  
    }
    cout << "\n"; 
}

int partition(int arr[], int l, int h){
    int pivot = l; 

    for(int i = h - 1; i > l; i--){
        if(arr[i] < arr[pivot]){
            int temp = arr[pivot+1]; 
            arr[pivot + 1] = arr[pivot]; 
            arr[pivot] = arr[i]; 
            arr[i] = temp;
            pivot++;
        }
    }
    return pivot;
}


void quicksort(int arr[], int l, int h){ 
    if (h > l){ 
        int p = partition(arr, l, h); 
        quicksort(arr, l, p-1);
        quicksort(arr, p + 1, h); 
    }   
}

int main(){
    
    int arr[] = {3,41,52,26,38,9, 57,9,49};
    int size = sizeof(arr)/sizeof(int);

    print (arr, size);
    quicksort(arr, 0, size); 
    print(arr, size);

    return 0; 
}


