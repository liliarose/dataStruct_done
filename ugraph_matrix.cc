#include <iostream>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>
#include <cstring>
#define v 9 
#define INF 0xFFFF
#include <iomanip>

using namespace std; 

int arr[128][128];

void add_edge(int from, int to, int dist){
	arr[from][to] += dist;
	arr[to][from] += dist;
}
void dfs(int x){
	bool visited[v];
	memset(&(visited), 0, sizeof(visited));
	stack <int> tmp;
	tmp.push(x);
	visited[x] = true;
	while(!tmp.empty()){
		int t = tmp.top();
		tmp.pop();
		cout << t << " ";
		for(int i = 0; i < v; i++){
			if(!visited[i] && arr[t][i] != 0){
				visited[i] = true;
				tmp.push(i);
			}
		}
	}
	cout << endl;
}
void bfs(int x){
	bool visited[v];
	memset(&(visited), 0, sizeof(visited));
	queue <int> tmp;
	tmp.push(x);
	visited[x] = true;
	while(!tmp.empty()){
		int t = tmp.front();
		tmp.pop();
		cout << t << " ";
		for(int i = 0; i < v; i++){
			if(!visited[i] && arr[t][i] != 0){
				visited[i] = true; 
				tmp.push(i);
			}
		}
	}
	cout << endl;
}

void print(){
	for(int i = 0; i < v; i++){
		for(int k = 0; k < v; k++){
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print(int arr[]){
	for(int i = 0; i < v; i++){
		cout << i << ": " << arr[i] << endl;
	}
}

void print(int arr[v][v]){
	for(int i = 0; i < v; i++){
		for(int k = 0; k < v; k++){
			cout.width(2);
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
int shortest_d(int from, int to){
	int dist[v];
	memset(&(dist), 0x7F, sizeof(dist));
	bool included[v];
	memset(&(included), 0, sizeof(included));
	dist[from] = 0;

	for(int i = 0; i < v-1; i++){
		int min = INF, min_index;	
		for(int k = 0; k < v; k++){
			if(!included[i] && dist[i] <= min){
				min_index = i;
				min = dist[i];
			}
		}
		included[min_index] = true;
		for(int k = 0; k < v; k++){
			if(!included[k] && arr[min_index][k] != 0 && (dist[min_index] + arr[min_index][k] < dist[k])){
				dist[k] = dist[min_index] + arr[min_index][k];
			}
		}
	}
	cout << "Distance from " << from << ": ";
	for(int i = 0; i < v; i++){
		cout << dist[i] << " ";
	}
	cout << endl;
	return dist[to];
}
*/

struct node{
	int id;
	int dist;
	node(int a, int b){
		id = a;
		dist = b;
	}
	friend bool operator < (const node &a, const node &b){
		return (a.dist > b.dist);
	}
};

void shortest_path(int from){
	bool visited[v];
	int dist[v];
	memset(&(visited), 0, sizeof(visited));
	memset(&(dist), 0x7F, sizeof(dist));
	
	priority_queue<node> q;
	node n(from, 0);
	q.push(n);
	dist[from] = 0;
	while(!q.empty()){
		n = q.top();
		q.pop();
		visited[n.id] = true;
		for(int i = 0; i < v; i++){
			if(!visited[i] && arr[n.id][i] > 0 && (arr[n.id][i] + dist[n.id]) < dist[i]){
				dist[i] = arr[n.id][i] + dist[n.id];
				q.push(node(i, dist[i]));
			}
		}

	}
	print(dist);
}

int shortest_path(int from, int to){
	int dist[v][v];
	for(int i = 0; i < v; i++){
		for(int k = 0; k < v; k++){
			if(i == k){
				dist[i][k] = 0;
			} else if(arr[i][k] > 0){
				dist[i][k] = arr[i][k];
			}
			else{
				dist[i][k] = INF;
			}
		}
	}
	for(int k = 0; k < v; k++){
		for(int j = 0; j < v; j++){
			for(int i = 0; i < v; i++){
				if((dist[j][k] + dist[i][k]) < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	print(dist);
	return dist[from][to];
}

int main(){
    add_edge(0, 1, 4);
	add_edge(0, 7, 8);
    add_edge(1, 7, 11);
	add_edge(1, 2, 8);
	add_edge(7, 8, 7);
	add_edge(7, 6, 1);
	add_edge(2, 8, 2);
	add_edge(6, 8, 6);
	add_edge(2, 5, 4);
	add_edge(6, 5, 2);
	add_edge(2, 3, 7);
	add_edge(3, 5, 14);
	add_edge(2, 4, 9);
	add_edge(5, 4, 10);

	print();
	bfs(0);
	dfs(0);
	shortest_path(0);
	cout << shortest_path(0, 4) << endl;
	cout << shortest_path(0, 5) << endl;
	//cout << shortest_d(0, 4) << endl;
}


