#include <iostream>
#include <algorithm>
#define SIZE 10

using namespace std;
int high;
void print(int arr[], int lim, int low = 0){
    for(int i = low; i < lim; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cp(int a1[], int a2[], int s1, int s2, int delta){
    for(int i = 0; i < delta; i++){
        a1[s1+i] = a2[s2 + i];
    }
}
// [low, mid) && [mid, high)
void merge(int arr[], int low, int mid, int hi){
    //cout << low << " " << mid << " " << hi << ": ";
    int tmp[hi-low+1], i, j, k;
    for(i = low, j = mid, k = 0; i < mid && j < hi; k++){
        if(arr[i] <= arr[j]){
           tmp[k] = arr[i];
           i++;
        } else {
            tmp[k] = arr[j];
            j++;
        }
        //cout << k << ": ";
        //print(tmp, k);
        //cout << "swapped\n";
    }
    if(i < mid){
       cp(tmp, arr, k, i, mid - i);
    } else if( j < hi){
        cp(tmp, arr, k, j, hi - j);
    }
    cp(arr, tmp, low, 0, hi-low);
    //print(arr, hi, low);
}

void merge_sort(int arr[], int N){
    int d, is, ie;
    for(d = 1; d < N; d*=2){
        for(is = 0, ie= 2*d; ie <= N; is+= d*2, ie+=d*2){
            merge(arr, is, ie -d, ie);
            //print(arr, i, i+2*d);
        }
        if(is < N && is - 2*d >= 0){
            //cout << "EXTRA: ";
            merge(arr, is - 2*d, is, N);
        }
    }
    //merge(arr, 0, d/2, N-1);
}

int binarySearch(int arr[], int lim, int key){
    int s = 0, e = lim;
    while(s <= e){
        int mid = (e+s)/2;
        if(arr[mid] == key) return mid;
        if(arr[mid] < key){
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}


int main(){
    //int tmp[] = {-2, -1, 0, 1};
    //merge(tmp, 0, 2, 4);
    //print(tmp, 4);
    int arr[] = {9, 8, 6, 4, 3, 1};
    //int arr[] = {1, 5, 1, 1,  -1 , 8, 9, 6, 7, 3, 4, 2, 0};
    //int arr[] = {1, 0, 1, 2, 2, 1};
    int lim = sizeof(arr)/sizeof(int);
    cout << lim << ": "; 
    print(arr, lim);
    merge_sort(arr, lim);
    print(arr, lim);
    cout << binarySearch(arr, lim, 6) << endl;
}



