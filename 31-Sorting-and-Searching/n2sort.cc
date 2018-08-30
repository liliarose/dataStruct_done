#include <iostream>
#include <algorithm>
#define SIZE 10

using namespace std;
void print(int arr[], int lim);

void bubble(int arr[], int lim){
    for(int i = 0; i < lim; i++){
        for(int j = 1; j < lim - i; j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void selection(int arr[], int lim){
    for(int i = 0, min; i < lim - 1; i++, min = i){
        for(int j = i+1; j < lim; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(a[i], a[j]);
    }
}

void insertion(int arr[], int lim){
    for(int )
}

void print(int arr[], int lim){
    for(int i = 0; i < lim; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    //int arr[] = {9, 8, 6, 4, 3, 1};
    //int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int arr[] = {1, 0, 1, 2, 2, 1};
    int lim = sizeof(arr)/sizeof(int);
    print(arr, lim);
    selection(arr, lim);
    print(arr, lim);
}



