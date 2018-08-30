#include <iostream>
#include <algorithm>
#define SIZE 10

using namespace std;
void print(int arr[], int lim);

void countingSort(int arr[], int lim){
    int c[SIZE];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < lim; i++){
        c[arr[i]]++;
    }
    //print(c, SIZE);
    for(int i = 0, curr = 0; i < lim;){
        if(c[curr] == 0)
            curr++;
        else {
            arr[i] = curr;
            c[curr]--, i++;
        }
    }
}

// only 0, 1, 2 sorting
void sort1(int arr[], int N){
    for(int i0 = 0, i = 0, i2 = N - 1; i <= i2;){
        if(arr[i] == 1) { i++; } 
        else if(arr[i] == 0){
            swap(arr[i], arr[i0]);
            i0++, i++;
        } else {
            swap(arr[i], arr[i2]);
            i2--;
        }
        //cout << i0 << " " << i << " " << i2 << "\t";
        //print(arr, N);
   }
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
    sort1(arr, lim);
    //countingSort(arr, lim);
    print(arr, lim);
}



