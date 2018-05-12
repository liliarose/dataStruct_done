#include <iostream>
#include <iomanip>
#define max_n 20
#define max_m 30

using namespace std; 

int graph[max_m][max_n], M, N;

void add_edge(int m, int n){
	graph[m][n] = 1;
}

void print();
void print(int arr[], int N);
void print(bool arr[], int N);
bool bpm(int m, int match[], int matched[]);
int max_match();


int main(){
	
	//add graph
	M = 3;
	N = 3;
	add_edge(0, 0);
	add_edge(0, 1);
	add_edge(1, 2);
	add_edge(1, 0);
	add_edge(1, 1);
	add_edge(2, 0);
	//add_edge(3, 2);
	//add_edge(3, 3);
	cout << max_match() << endl;
	return 0;
}

bool bpm(int m, int match[], bool matched[]){
	for(int i = 0; i < N; i++){
		if(graph[m][i] == 1 && !matched[i]){	
			//cout << "entered " << i << endl;
			//print(match, N);
			//print(matched, N);
			if(match[i] == -1){
				match[i] = m;
				return true;
			}
			matched[i] = true; 
			if(bpm(match[i], match, matched)){
				matched[i] = false;
				match[i] = m;
				return true;
			}
			matched[i] = false;
		}
	}
	return false;
}



int max_match(){
	int match[N], maxi = 0;
	bool matched[N];
	for(int i = 0; i < N; i++){
		match[i] = -1;
		//matched[i] = false;
	}

	for(int i = 0; i < M; i++){
		/*for(int k = 0; k < N; k++){
			 matched[k] = false;
		}*/
		//print(matched, N);
		if(bpm(i, match, matched)){
			maxi++;
		}
		//cout << "done\n\n";
		//print(match, N);
	}
	return maxi;
}

void print(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void print(int arr[], int N){
	for(int i = 0; i < N; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print(bool arr[], int N){ 
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
}
