#include <iostream>
#include <forward_list>
#include <list>
#include <queue>
#include <stack>
#include <cstring>
#define v 8

using namespace std; 

int arr[128][128];

void add_edge(int from, int to){
    arr[from][to] +=1; 
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

int main(){
    add_edge(0, 1); 
    add_edge(0, 6); 
    add_edge(1, 2); 
    add_edge(1, 3); 
    add_edge(2, 3); 
    add_edge(3, 4); 
    add_edge(3, 6); 
    add_edge(4, 5); 
    add_edge(6, 7); 
    add_edge(7, 4); 
    add_edge(7, 5); 
    print();
    bfs(0);
    dfs(0);
}


