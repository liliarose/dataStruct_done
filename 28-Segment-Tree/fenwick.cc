#include <iostream>
#define MAX 50

using namespace std;

int fenwick[MAX], N;

void update(int id, int diff){
	for(int i = id + 1; i <=N; i+= i&(-i)){
		fenwick[i] += diff;
	}
}

int query(int s, int e){
	int sum = 0;
	for(int i = e+1; i > 0; i-= i&(-i)){
		sum += fenwick[i];
	}
	for(int i = s; i > 0; i-= i&(-i)){
		sum -= fenwick[i];
	}
	return sum;
}

int main(){
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	N = sizeof(freq)/sizeof(freq[0]);
	for(int i = 0; i < N; i++){
		update(i, freq[i]);
	}
	cout << query(3, 5) << endl;
	update(3, 6);
	cout << query(3, 5) << endl;
}

