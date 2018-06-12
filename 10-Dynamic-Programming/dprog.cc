/*
ID: your_id_here
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAX 30

using namespace std;

int dp[MAX], n = 0;

int fib_rec(int num){
	if(num == 1){
		return 1; 
	}
	return fib_rec(n - 1) + fib_rec(n-2);
}

int fib_tb(int num){
	if(dp[num] != 0) return dp[num]; 
	dp[num] = fib_tb(n-1) + fib_tb(n-2);
	return dp[num];
}

int fib_dp(int num){
	if(num <= n) return dp[num];
	if(n == 0){
		dp[0] = 1; 
		dp[1] = 1;
		n = 1; 
	}
	for(int i = n+1; i <= num; i++){
		 dp[i] = dp[i-1] + dp[i-2];
	}
	n = num; 
	return dp[num];
}
/*
dp[0] = 1;
dp[1] = 1;
for(int i = n+1; i <= num; i++){
	dp[i] = dp[i-1] + dp[i-2];
}
*/
/*
int fib(int num){
	for(int prev2 = 1, prev1 = 1, curr, i = 2; i <= num; i++){
		curr = prev
	}
}
*/
//binomial coefficient 

int lcs_rec(char s1[], char s2[], int a, int b){
	if(a == 0 || b == 0) return 0; 
	if(s1[a-1] == s2[b-1]){ 	
		return (1+ lcs_rec(s1, s2, a - 1, b - 1));
	} else {
		int i = lcs_rec(s1, s2, a - 1, b);
		int k = lcs_rec(s1, s2, a, b - 1);
		return (i > k) ? (i):(k);
	}
}
/*
int lcs_rec(string s1, string s2){
	if(s1.back() == s2.back()){
		return (1+ lcs_rec(s1.substr(0, length() -1), s2.substr(0, length() -1)));
	} else {
		int 
	}

}
*/

int arr[MAX][MAX];

int lcs_dp(char s1[], char s2[], int a, int b){
	for(int i = 1; i <= a; i++ ){
		for(int k = 1; k <= b; k++){
			if(s1[i] == s2[k]){
				arr[i][k] = 1 + arr[i-1][k-1];
			} else {
				arr[i][k] = (arr[i][k-1] > arr[i-1][k]) ? (arr[i][k-1]):(arr[i-1][k]);
			}
		}
	}
	return arr[a][b];
}
/*
void print_lcs(char s1[], char s2[], int a, int b){
	string str = 
	for(int i = a, k = b; i > 0 && k > 0; ){
		if(arr[i][k-1] == arr[i][k]){
			k = k -1;
			s1[i]; 
		}
	}
}
*/

int getW(int ind, int i, int w[], int a);
int ar[MAX][MAX];
/*
int knapsack(int w[], int v[], int lim, int a){
	for(int i = 1; i <= a; i++){
		int ind = 0, wght = getW(ind, i, w, a);
		for(int k = 0; k <= lim; k++){
			if(k == wght){
				ar[i][k] = v[ind] + ar[i-1][k-1];
				cout << "weight"
				ind++;
				wght = getW(ind, i, w, a);
				//cout << i << ": " << wght << " " << v[ind -1] << endl;
			} else {
				ar[i][k] = (ar[i][k-1] > ar[i-1][k]) ? (ar[i][k-1]):(ar[i-1][k]);
			}
		}
	}
	return ar[a][lim];
}
*/


int knapsack(int w[], int v[], int lim, int a){
    for(int i = 1; i <= a; i++){
        for(int k = 0; k <= lim; k++){
       		if(w[i-1] <= k){
				ar[i][k] = ((v[i-1] + ar[i-1][(k-w[i-1])]) > ar[i-1][k]) ? (v[i-1] + ar[i-1][(k-w[i-1])]):(ar[i-1][k]);
			} else {
				ar[i][k] = ar[i-1][i-k];
			}
		}
    }
    return ar[a][lim];
}


void print(int arr[MAX][MAX], int a, int b){
	for(int i = 0; i < a; i++){
		for(int k = 0; k < b; k++){
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
}

/*
int getW(int ind, int i, int w[], int a){
	if(a < ind) return 0;
	if(i == 1) return w[ind];
	int wght = 0;
	int t = ((ind - i + 1) > 0)?(ind - i + 1): (0);
	//cout << "t: " << t << " " << (ind - i + 1) << endl;
	for(int j = ind; j >= t ; j--){
		wght += w[j];
	}
	return wght;
}*/

int main() {
	int w[] = {1, 2, 3};
	int v[] = {60, 100, 120};
	int lim = 5, siz = 3;
	cout << knapsack(w, v, lim, siz) << endl;
	//print(ar, siz+1, lim+1);
/*	cin >> a;
	cin >> b; */
//    cout << lcs_dp(a, b, 6, 6) << endl;
	return 0;
}












