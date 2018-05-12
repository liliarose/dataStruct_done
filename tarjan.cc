#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 10
#define MM 100

using namespace std;

int graph[MAX][MAX], n, N;
int disc[MAX], low[MAX];
bool in_stack[MAX];
stack<int> st;

void addEdge(int from, int to){
	graph[from][to] = 1;
}

void rm_edge(int from, int to){
	graph[from][to] = 0;
}

void tarjan();

int main(){
/*
	N = 5;
	addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
	tarjan();

	N = 3;
  	addEdge(0, 1);
  	addEdge(1, 2);
  	addEdge(2, 0);
	cout << dp_ham() << endl;

	N = 6;
  	addEdge(1, 0);
  	addEdge(0, 2);
  	addEdge(2, 1);
  	addEdge(0, 3);
  	addEdge(3, 4);
  	addEdge(3, 2);
  	addEdge(3, 1);
  	addEdge(2, 4);
	addEdge(1, 5);
*/	
	N = 10;
	addEdge(0,1);
	addEdge(0,3);
    addEdge(1,2);
	addEdge(1,4);
    addEdge(2,0);
	addEdge(2,6);
    addEdge(3,2);
    addEdge(4,5);
	addEdge(4,6);
    addEdge(5,6);
	addEdge(5,7);
	addEdge(5,8);
	addEdge(5,9);
    addEdge(6,4);
    addEdge(7,9);
    addEdge(8,9);
    addEdge(9,8);	

	tarjan();

	return 0;
}

void dfs(int curr){
	disc[curr] = n;
	low[curr] = n;
	n++;
	in_stack[curr] = true;
	st.push(curr);
	for(int i = 0; i < N; i++){
		if(graph[curr][i]){
			if(disc[i] == -1){
				dfs(i);
				low[curr] = (low[i] > low[curr]) ? (low[curr]):(low[i]);
			} else if(in_stack[i]){
				low[curr] = (disc[i] > low[curr]) ? (low[curr]):(disc[i]);
			}
		}
	}
	
	//cout << low[curr] << " " << disc[curr] << endl;
	if(low[curr] == disc[curr]){
		while(!st.empty()){
			int v = st.top();
			cout << v << " ";
			st.pop();
			if(disc[curr] == disc[v]){
				cout << endl;
				//cout << low[v] << " " << disc[curr] << " " << v << " " << curr << endl;
				break;
			}
		}
	}
}

void tarjan(){
	for(int i = 0; i < N; i++){
		disc[i] = -1;
	}	
	for(int i = 0; i < N; i++){
		if(disc[i] == -1){
			dfs(i);
		}
	}
}













