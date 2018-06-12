#include <iostream>
#include <queue>
#define MAX 20

using namespace std;

int graph[MAX][MAX], N;
int dfs_count(int x);
void add_edge(int i, int j){
	graph[i][j] = 1;
	graph[j][i] = 1;
}

void rm_edge(int i, int j){
	graph[j][i] = -1;
	graph[i][j] = -1;
}

bool is_bridge(int a, int b){
	rm_edge(a, b);
	int i = dfs_count(a);
	int j = dfs_count(b);
	add_edge(a, b);
	return i > j; 
}

int dfs_count(int x){
	bool visited[N];
	memset(visited, 0, N);
	int cnt = 0; 
	queue <int> q;
	q.push(x);
	//cout << "cnt: " << cnt << endl;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		if(!visited[tmp]){
			visited[tmp] = true; 
			cnt++;
			for(int i = 0; i < N; i++){
				if(graph[tmp][i] > 0 && !visited[i]){
					q.push(i);
				}
			}
		}
	}
	//cout << "cnt: " << cnt << endl;
	return cnt;
}


bool is_valid(int a, int b){
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(graph[a][i] > 0){
			cnt++;
		}
	}
	return (cnt == 1);
}

void dfs(int beg){
	for(int i = 0; i < N; i++){
		//cout << "graph[" << beg << "][" << i << "]: " << graph[beg][i] << endl;	
		if(graph[beg][i] > 0 && (!is_bridge(beg, i) || is_valid(beg, i))){
				cout << beg << " - " << i << "\t";
				rm_edge(beg, i);
				dfs(i);
		}
	}
}


void fleury(){
	int count = 0;
	int start = 0; 

	for(int i = 0; i < N; i++){
		int degree = 0;
		for(int j = 0; j < N; j++){
			if(graph[i][j] > 0) {
				degree++;	
			}
		}
		if(degree&1){
			//cout << "odd degree: " << i << endl;
			count++;
			start = i;
		}
	}
	/*
	if(count != 0 && count != 2) {
		cout << "No Euclidean trail\n";
		return;
	}
	*/
	dfs(start);
	cout << endl;
}


int main(){
	N = 4;
	add_edge(0, 1);
  	add_edge(0, 2);
  	add_edge(1, 2);
  	add_edge(2, 3);
	fleury();
	
	N = 3;
  	add_edge(0, 1);
  	add_edge(1, 2);
  	add_edge(2, 0);
	fleury();

	N = 5;
  	add_edge(1, 0);
  	add_edge(0, 2);
  	add_edge(2, 1);
  	add_edge(0, 3);
  	add_edge(3, 4);
  	add_edge(3, 2);
  	add_edge(3, 1);
  	add_edge(2, 4);
	fleury();
}





