/*
ID: your_id_here
TASK: test
LANG: C++                 
*/
#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#define MAX 20
#define N 9  
#define INF 0xFFFF

using namespace std;

struct node{
	int dst;
	int wgt;
	node(int a = 0, int b = 0){
		dst = a;
		wgt = b;
	}
	bool operator < (const node &b) const{
		return wgt > b.wgt;
	}
};

struct edge{
	int src;
	int dst;
	int wgt;
	edge(int a = 0, int b = 0, int c = 0){
		src = a;
		dst = b;
		wgt = c;
	}
	bool operator < (const edge &b) const{
		return wgt > b.wgt;
	}
};

list <node> graph[MAX];
edge new_graph[MAX];
//add_edge only for initializing graph 
void print(edge arr [MAX]);
void add_edge(int a, int b, int c);
int find(int parent[], int i);
bool is_Cycle(int parent[], int x, int y);
void Union(int parent[], int x, int y);
/*
void prim(){
	bool visited[N];
	memset(visited, 0, sizeof(visited));
	priority_queue <node> tmp;
	node curr = graph[0].front();
	tmp.push(curr);
	while(!tmp.empty()){
		curr = tmp.top();
		if(!visited[curr.dst]){
			node minE(0, INF);
			for (list<node>::iterator it = graph[curr.dst].begin(); it != graph[curr.dst].end(); ++it){
				if(!visited[(*it).dst]){
					tmp.push(*it);
					//cout << "pushed: " << (*it).dst << "\t" << (*it).wgt << "\n";
				}
				if((*it).wgt < minE.wgt){
					minE = *it;
					cout << "min changed: " << minE.dst << "\t" << minE.wgt << "\n";
				}
			}
			new_graph[count] = (edge(curr.dst, minE.dst, minE.wgt));
			cout << new_graph[count].src <<  " - " << new_graph[count].dst << "\t" << new_graph[count].wgt << endl; 
			visited[curr.dst] = true;
			count++;
		}
		tmp.pop();
	}
}
*/

void prim(){
	bool visited[N];
	int count = 0;
    memset(visited, 0, sizeof(visited));
    priority_queue <edge> tmp;
	visited[0] = true;
	for(list<node>::iterator it = graph[0].begin(); it != graph[0].end(); ++it){
		tmp.push(edge(0, (*it).dst, (*it).wgt));
	}
	while(!tmp.empty() && count < N -1){
		edge curr = tmp.top();
		cout << curr.src << " - " << curr.dst << "\t" << curr.wgt << "\n";
		if(curr.dst <= N && !visited[curr.dst]){
			//cout << curr.src << " - " << curr.dst << "\t" << curr.wgt << "\n";	
			visited[curr.dst] = true;
			new_graph[count] = edge(curr.src, curr.dst, curr.wgt);
			cout << new_graph[count].src << " - " << new_graph[count].dst << "\t" << new_graph[count].wgt << "\n";
			for(list<node>::iterator it = graph[curr.dst].begin(); it != graph[curr.dst].end(); ++it){
				if(!visited[curr.dst]){
					tmp.push(edge(curr.dst, (*it).dst, (*it).wgt));
				}
			}
			count++;
		}
		tmp.pop();
	}

}



int main() {

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
    add_edge(2, 3, 9); 
    add_edge(5, 4, 10);
    add_edge(3, 4, 9); 
	prim();
	//print(new_graph);
	return 0;
}


int find(int parent[], int i){
	while(parent[i] != -1){
		i = parent[i];
	}
	return i;
}

bool is_Cycle(edge arr[MAX], int x, int y){
	int parent[MAX];
	for(int i = 0; i < N; i++){
		parent[arr[i].dst] = arr[i].src;
	}
	int a = find(parent, x);
	int b = find(parent, y);
	return (a == b);
}

void Union(int parent[], int x, int y){
	int a = find(parent, x);
	int b = find(parent, y);
	if(a != b) {
		parent[a] = b; 
		parent[b] = a;
	}
}

void add_edge(int a, int b, int c){
	graph[a].push_front(node(b, c));
	graph[b].push_front(node(a, c));
	//cout << tmp.src << " - " << tmp.dst << "\t" << tmp.wgt << "\n";
}

void print(edge arr [MAX]){
	for(int i = 0; i < N - 1; i++){
		cout << arr[i].src << " - " << arr[i].dst << "\t" << arr[i].wgt << "\n"; 
	}
}



