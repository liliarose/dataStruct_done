#include <iostream>
#include <string>
#define MAX 100

using namespace std;

int arr[MAX], N; 

int query(int i, int j);
void update(int i, int diff);

int main(){
    int a[] = {1, 3, 5, 7, 9, 11};
    N = sizeof(a)/sizeof(int);
    for(int i = 0; i < N; i++){
        arr[i] = a[i];
    }
    cout << query(0, N-1) << endl;
    cout << query(1, 3) << endl;
    update(1, 10);
    cout << query(0, N-1) << endl;
    cout << query(1, 3) << endl;
}

int query(int i, int j){
    int sum = 0; 
    for(int k = i; k<=j; k++){
        sum += arr[k];
    }
    return sum;
}

void update(int i, int diff){
    arr[i] += diff;
}


