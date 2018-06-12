#include <iostream>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>

using namespace std; 

class graph{
public:
	graph(int size){
		V = size;
		data = new list <int> [V];
	}
	void add_edge(int from, int to){
		data[from].push_back(to);
	}
	void it_bfs(int x = 0){
	 	bool visited[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }   
        queue <int> tmp;
        tmp.push(x);
        visited[x] = true;
        while(!tmp.empty()){
            int temp = tmp.front();
            tmp.pop();
            cout << temp << " ";
			for(list <int>::iterator it = data[temp].begin(); it != data[temp].end(); ++it){
                if(!visited[*it]){
                    visited[*it] = true;
                    tmp.push(*it);
                }   
            }   
        }
	}
	void it_dfs(int x = 0){
		bool visited[V]; 
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		stack <int> tmp; 
		tmp.push(x);
		visited[x] = true;
		while(!tmp.empty()){
			int temp = tmp.top();
			tmp.pop(); 
			cout << temp << " ";
			for(list <int>::iterator it = data[temp].begin(); it != data[temp].end(); ++it){
				if(!visited[*it]){
					tmp.push(*it);
					visited[*it] = true;
				}
			}
		}
		cout << endl;
	}
	
	bool reachable(int src, int to){
		bool visited[V];
		for(int i = 0; i < V; i++){
			visited[i] = false;
		}
		queue <int> tmp;
		tmp.push(src);
		visited[src] = true;
		while(!tmp.empty()){
			int temp = tmp.front();
			tmp.pop();
			if(temp == to) return true; 
			for(list <int>::iterator it = data[temp].begin(); it != data[temp].end(); ++it){
				if(!visited[*it]){
					visited[*it] = true;
					tmp.push(*it);
				}
			}
		}
		return false;
	}
	void dfs(int x, bool visited[]){
		visited[x] = true;
		cout << x << " ";
		for(list <int>::iterator it = data[x].begin(); it != data[x].end(); ++it){
			if(!visited[*it]){ 
				dfs(*it, visited); 
			}
		}
	}
	void dfs(int x = 0){
		bool visited[V];
		for(int i = 0; i < V; i++){
			visited[i] = false; 
		}
		dfs(x, visited);
		cout << "\n";
	}
private: 
	int V;
	list<int> *data;

};

int main(){
	graph x(8); 
	x.add_edge(0, 1);
	x.add_edge(0, 6);
	x.add_edge(1, 2);
	x.add_edge(1, 3);
	x.add_edge(2, 3);
	x.add_edge(3, 4);
	x.add_edge(3, 6);
	x.add_edge(4, 5);
	x.add_edge(6, 7);
	x.add_edge(7, 4);
	x.add_edge(7, 5);
	x.dfs();
	x.it_dfs();
	x.it_bfs();
	cout << x.reachable(0, 7) << endl;
	cout << x.reachable(3, 7) << endl;
	cout << x.reachable(7, 0) << endl;
	cout << x.reachable(1, 6) << endl;
	cout << x.reachable(6, 2) << endl;
}


