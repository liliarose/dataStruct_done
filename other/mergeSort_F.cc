#include <iostream>

using namespace std; 

int main(){
    
    int arr[] = {2, 34,5, 8, 10, 2, 3, 12, 455, 84, 9, 12, 233, 54543, 213}; 
    int size = sizeof(arr)/sizeof(int);
    int sorted[size];

    merge_sort(arr, size, sorted);
    cout << "FINAL SORTED: ";
    print(sorted, 0, size);
    return 0; 
}

//figures out the lengths to sort 
void merge_sort(int A[], int size, int B[]){

    for(int width = 1, i; width < size; width *= 2){
        cout << "WIDTH: " << width << endl;
        //print(A, 0, size); 
        for(i = 2*width; i < size; i+= 2 * width){
            // upper limit is exclusive, & lower limit is inclusive
            merging(A, i - 2*width, i - width, i, B);
        }
        if(i != size){
            merging(A, i - 2*width, i - width, size, B); 
        }
        swap(A, B);
        //print(A, 0, size);
    }
}

//upper limit is exclusive, & lower limit is inclusive
void merging(int A[], int low, int mid, int high, int B[]){
    cout << "Lower lim: " << low << "\tUpper Lim: " << high << endl;
    print(A, low, high); 

    int i = low, k = mid; 
    for(int curr = low; curr < high; curr++){
        if(i < mid && k < high){
            if(A[i] < A[k]){
                B[curr] = A[i];
                i++;
            }
            else{
                B[curr] = A[k];
                k++; 
            }
        }
        else if (i >= mid){
            B[curr] = A[k];
            k++;
        }
        else{
            B[curr] = A[i];
            i++;
        }
    }

    print(B, low, high);

}

//not really swap as just changin A to B
void swap(int A[], int B[], int limit){
    for(int i = 0; i < limit; i++){
        A[i] = B[i];
    }
}










