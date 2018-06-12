#include <iostream>
#include <iomanip>
#include <queue>
#define MAX 15
#define INF 2147483647

using namespace std; 

int graph[MAX][MAX], N;
int resid[MAX][MAX];

void addEdge(int from, int to, int w){
    graph[from][to] = w;
}

int MinCut(int s, int f);
void print(int parent[]);
void initialize(int arr[], int i);

int main(){
	/*N = 4;
    addEdge(0, 1, 3);
    addEdge(0, 2, 2);
    addEdge(1, 2, 5);
    addEdge(1, 3, 2);
    addEdge(2, 3, 3);
	*/
	/*N = 6;
	addEdge(0, 1, 5);
	addEdge(0, 2, 4);
	addEdge(2, 1, 3);
	addEdge(1, 3, 4);
	addEdge(2, 4, 3);
	addEdge(3, 4, 1);
	addEdge(3, 5, 2);
	addEdge(4, 5, 8);
	*/
	N = 6;
	addEdge(0, 1, 16);
	addEdge(0, 2, 13);
	addEdge(1, 2, 10);
	addEdge(2, 1, 4);
	addEdge(1, 3, 12);
	addEdge(2, 4, 14);
	addEdge(3, 2, 9);
	addEdge(4, 3, 7);
	addEdge(4, 5, 4);
	addEdge(3, 5, 20);

	cout << MinCut(0, N-1) << endl;	
	return 0;
}

bool bfs(int s, int f, int parent[]){
	queue<int> q;
	q.push(s);
	parent[s] = s;
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(int i = 0; i < N; i++){
			if(resid[k][i] && parent[i] == -1){
				q.push(i);
				parent[i] = k;
			}
		}
	}
	return parent[f] != -1;
}

int MinCut(int s, int f){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			resid[i][j] = graph[i][j];
		}
	}

	int parent[N], mf = 0;
	initialize(parent, -1);
	while(bfs(s, f, parent)){
		int curr = f, tmp = INF;
		while(curr != s){
			if(tmp > resid[parent[curr]][curr]){
				tmp = resid[parent[curr]][curr];
			}
			curr = parent[curr];
		}
		mf += tmp;
		curr = f;
		while(curr != s){
			resid[parent[curr]][curr] -= tmp;
			resid[curr][parent[curr]] += tmp;
			curr = parent[curr];
		}
		initialize(parent, -1);
	}
	cout << "mf: " << mf << endl;
	bool reachable[N];
	memset(reachable, 0, sizeof(reachable));
	//initialize(reachable, -1);
	reachable[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i = 0; i < N; i++){
			if(resid[tmp][i] && !reachable[i]){
				q.push(i);
				reachable[i] = 1;
			}
		}
	}
	//print(reachable);
	int cutW = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(reachable[i] && !reachable[j] && graph[i][j]){
				cutW += graph[i][j];
				cout << "i: " << i << "\tj: " << j << " " << graph[i][j] << endl;
			}
		}
	}

	return cutW;
}

void initialize(int arr[], int key){
	for(int i = 0; i < N; i++){
		arr[i] = key;
	}
}

void print(int parent[]){
	for(int i = 0; i < N; i++){
		cout << parent[i] << " ";
	}
	cout << endl;
}


