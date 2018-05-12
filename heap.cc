#include <iostream>
#define size 25

using namespace std;

void heapsort(int arr[], int N);
void create_arr_heap(int arr[], int N);
void heapify(int arr[], int i, int lim);
void heapify_min(int arr[], int i, int lim);
void print(int arr[], int N){
	for(int i = 0; i < N; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
}

int main(){

	int arr[] = { 4, 22, 23, 0, 21, 20, 9, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 8, 7, 5, 6, 4, 3, 2, 1};
	heapsort(arr, size); 
	print(arr, size);
}

void swap(int &a, int &b){
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

void heapsort(int arr[], int N){
	for(int lim = N; lim > 1; lim--){
		create_arr_heap(arr, lim);
		swap(arr[0], arr[lim - 1]);
		//print(arr, N);
	}
}

void create_arr_heap(int arr[], int N){
	for(int i = (N - 1)/2; i >= 0; i--){
		heapify_min(arr, i, N);
	}
}

void heapify(int arr[], int i, int lim){
	int l = 2 * i + 1, r = 2 * i + 2, largest = i;

	if(l < lim && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < lim && arr[r] > arr[largest]){
		largest = r; 
	}
	if(largest != i){
		swap(arr[largest], arr[i]);
		heapify(arr, largest, lim);
	}
}

void heapify_min(int arr[], int i, int lim){
    int l = 2 * i + 1, r = 2 * i + 2, smallest= i;

    if(l < lim && arr[l] < arr[smallest]){
        smallest= l;
    }   
    if(r < lim && arr[r] < arr[smallest]){
        smallest= r;  
    }   
    if(smallest != i){ 
        swap(arr[smallest], arr[i]);
        heapify(arr, smallest, lim);
    }   
}


