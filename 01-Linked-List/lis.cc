#include <iostream>
#define MAX 20

using namespace std;
int dp[MAX], N;
int lis(int arr[]);

int main(){
	int arr[] = {50, 3, 10, 7, 40, 80};
	N = sizeof(arr)/sizeof(int); 
	cout << lis(arr) << endl;
}

int lis(int arr[]){
	for(int i = 0; i < N; i++){
		dp[i] = 1;
		for(int j = i -1 ; j >= 0; j--){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int maxi = 1;
	for(int i = 0; i < N; i++){
		if(maxi < dp[i])
			maxi = dp[i];
	}
	/*int tmp = 0;
	for(int j = N-1, count = max; j >= 0; j++){
		
	}*/
	return maxi;
}

