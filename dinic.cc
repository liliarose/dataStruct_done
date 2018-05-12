#include <iostream>
#include <iomanip>
#include <queue>
#define MAX 15
#define INF 2147483647

using namespace std; 

int graph[MAX][MAX], N;

void addEdge(int from, int to, int w){
    graph[from][to] = w;
}

int maxFlow(int s, int f);
bool bfs(int s, int f, int parent[]);
int blocking(int s, int f, int level[], int flow = INF);
void print(int parent[]);
void initialize(int arr[], int i);

int main(){
	/*
	N = 6;
	addEdge(0, 1, 16 );
    addEdge(0, 2, 13 );
    addEdge(1, 2, 10 );
    addEdge(1, 3, 12 );
    addEdge(2, 1, 4 );
    addEdge(2, 4, 14);
    addEdge(3, 2, 9 );
    addEdge(3, 5, 20 );
    addEdge(4, 3, 7 );
    addEdge(4, 5, 4);

	addEdge(0, 1, 3 );
    addEdge(0, 2, 7 ) ;
    addEdge(1, 3, 9);
    addEdge(1, 4, 9 );
    addEdge(2, 1, 9 );
    addEdge(2, 4, 9);
    addEdge(2, 5, 4);
    addEdge(3, 5, 3);
    addEdge(4, 5, 7 );
    addEdge(0, 4, 10);
	
	 addEdge(0, 1, 10);
     addEdge(0, 2, 10);
     addEdge(1, 3, 4 );
     addEdge(1, 4, 8 );
     addEdge(1, 2, 2 );
     addEdge(2, 4, 9 );
     addEdge(3, 5, 10 );
     addEdge(4, 3, 6 );
     addEdge(4, 5, 10 );	
	*/

	N = 4;
	addEdge(0, 1, 3);
	addEdge(0, 2, 2);
	addEdge(1, 2, 5);
	addEdge(1, 3, 2);
	addEdge(2, 3, 3);
	
	/*N = 5;
	addEdge(1, 2, 40);
	addEdge(1, 4, 20);
	addEdge(2, 4, 20);
	addEdge(2, 3, 30);
	addEdge(3, 4, 10);
	*/
	cout << maxFlow(1, 3) << endl;
	return 0;
}

bool bfs(int s, int f, int level[]){
	initialize(level, -1);
	queue<int> q;
	q.push(s);
	level[s] = 0;
	while(!q.empty()){
		int i = q.front();
		q.pop();
	//	cout << "N: " << N << endl;
		for(int k = 1; k < N; k++){
	//		cout << i << " " << k << ": " << graph[i][k] << endl;
			if(graph[i][k] && level[k] == -1){
				q.push(k);
				level[k] = level[i] + 1;
	//			cout << "level i: " << level[i] << "\t" << "level k: " << level[k] << endl;
			}
		}
		//print(level);
	}
	//print(level);
	return level[f] != -1;
}

int blocking(int s, int f, int level[], int flow){
	//cout << s << " ";
	if(s == f){
		return flow;	
	}
	for(int i = 1, t = 0; i < N; i++){
		//cout << i << " ";
		if(graph[s][i] && level[s]+1 == level[i]){
			//cout << " level: " << level[i] << endl;
			t = blocking(i, f, level, min(flow, graph[s][i]));
			//cout << t << endl;
			if(t != 0){
				//cout << i << " level: " << level[i] << endl;
				graph[s][i] -= t;
				graph[i][s] += t;
				return t;
			}
			//cout << "\nback to looping\n";
		}
	}
	//cout << "\nout of loop\n";
	return 0;
}

int maxFlow(int s, int f){
	int level[N], mf = 0, tmp;
	while(bfs(s, f, level)){
		tmp = 1;
		while(tmp != 0){
			//cout << " kk " << endl;	
			tmp = blocking(s, f, level);
			mf += tmp;
			//cout << "tmp: " << tmp << endl;
		}
	}
	return mf;
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


