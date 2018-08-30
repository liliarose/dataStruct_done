#include <iostream>
#include <algorithm>
#define SIZE 10

using namespace std;
int high;
void print(int arr[], int lim, int low = 0);
int partition(int arr[], int l, int h){
    int i = l+1, ih = h;
    while(i <= ih){
        if(arr[i] > arr[l]){
            swap(arr[i], arr[ih]);
            ih--;
        } else {
            i++;
        }
    }
    swap(arr[l], arr[ih]);
    return ih;
}

void qsort(int arr[], int l, int hi){
    if(l < hi) {
        int p = partition(arr, l, hi);
        qsort(arr, l, p - 1);
        qsort(arr, p + 1, hi);
    }
}


void print(int arr[], int lim, int low){
    for(int i = low; i < lim; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    //int arr[] = {9, 8, 6, 4, 3, 1};
    int arr[] = {1, 5, 1, 1,  -1 , 8, 9, 6, 7, 3, 4, 2, 0};
    //int arr[] = {1, 0, 1, 2, 2, 1};
    int lim = sizeof(arr)/sizeof(int);
    print(arr, lim);
    qsort(arr, 0, lim - 1);
    //countingSort(arr, lim);
    print(arr, lim);
}



