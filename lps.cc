#include <iostream>
#include <algorithm>
#define MAX 20

using namespace std;

int lps_td(char s[], int a, int b);
int lps_r(char s[], int a, int b);
int lps_b(char s[], char buff[], int a, int b, int N);
int lps_bu(char s[], int N);
bool pd(char s[], int N);
void print(int arr[MAX][MAX], int N);
int dp[MAX][MAX];

int main(){
	
	char s[] = "GEEKS FOR GEEKS";
	int len = 15;
	char buff[len];
	cout << lps_b(s, buff, 0, 0, len) << endl;
	cout << lps_r(s, 0, len-1) << endl;
	cout << lps_td(s, 0, len-1) << endl;
	print(dp, len);
	cout << endl << lps_bu(s, len) << endl;
	print(dp, len);
	return 0;
}

int lps_bu(char s[], int N){
	/*for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			dp[i][j] = 0;
		}
	}*/

	for(int i = 0; i < N; i++){
		dp[i][i] = 1; 
		if(i < N-1){
			dp[i][i+1] = (s[i] == s[i+1])? (2):(1); 
		}
	}
	for(int l = 2; l < N; l++){
		for(int i = 0, j = l; j < N; i++, j++){
			dp[i][j] = (s[i] == s[j])? (2 + dp[i][j-1]): (max(dp[i][j-1], dp[i+1][j]));
		}
	}
	return dp[0][N-1];
}

int lps_td(char s[], int a, int b){
	if(dp[a][b]){
	} else if(a == b){
		dp[a][b] = 1;
	} else if(a+1 == b){
		dp[a][b] = (s[a] == s[b]) ? (2):(1);
	} else if(s[a] == s[b]){
		dp[a][b] = 2 + lps_td(s, a+1, b-1);
	} else {
		dp[a][b] = max(lps_td(s, a, b-1), lps_td(s, a+1, b));
	}
	return dp[a][b];
}

int lps_r(char s[], int a, int b){
	if(a == b)
		return 1;
	if(a +1 == b){
		if(s[a] == s[b])
			return 2;
		return 1;
	}
	if(s[a] == s[b]){
		return 2 + lps_r(s, a+1, b-1);
	}
	int tmp = lps_r(s, a, b-1);
	int tmp1 = lps_r(s, a+1, b);
	return (tmp > tmp1) ? (tmp):(tmp1);		
}

int lps_b(char s[], char buff[], int a, int b, int N){
	//cout << a << " " << b << endl;
	if(a == N){
		//buff[b] = 0;
		if(pd(buff, b))
			return b;
		else 
			return 0;
	} 
	buff[b] = s[a];
	int j = lps_b(s, buff, a+1, b+1, N);
	int k = lps_b(s, buff, a+1, b, N);
	return max(j, k);
}

bool pd(char s[], int N){
	for(int i = 0, j = N -1; i < j; i++, j--){
		if(s[i] != s[j])
			return false;
	}
	return true;
}

void print(int arr[MAX][MAX], int N){
	for(int i =0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}



