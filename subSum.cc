#include <iostream>
#include <fstream>
#define MAX 20

using namespace std; 
/*
bool find_subSum(int set[], int n, int key, int sum){
	if(sum - set[n] < 0)
		return find_subSum(set, n-1, key, sum);
	return (find_subSum(set, n-1, key, sum) || find_subSum(set, n, key, sum - set[n]));
}
*/

bool table[MAX][MAX];

bool find_subSum(int n, int arr[], int key){
	table[0][0] = 1;	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= key; j++){
			if(j - arr[i - 1] < 0){
				table[i][j] = table[i - 1][j];	
			} else {
				table[i][j] = (table[i - 1][j] || table[i - 1][j - arr[i - 1]]);
			}
		}
	}
	return table[n][key];
}

void print(int n, int key){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < key; j++){
			cout << table[i][j] << " ";	
		}
		cout << endl;
	}
}


int main(){
	int set[] = {3, 34, 4, 12, 5, 2};
	int key = 9;
	int N = 6;
	cout << find_subSum(N, set, key) << endl;
	print(N, key);
}


