#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 10
#define MM 100

using namespace std;

int graph[MAX][MAX], graph1[MAX][MAX], visited[MAX], N;
stack<int> st;

void addEdge(int from, int to){
    graph[from][to] = 1;
}

void rm_edge(int from, int to){
    graph[from][to] = 0;
}

void kosaraju();

int main(){

    N = 5;
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
    kosaraju();
/*
    N = 3;
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 0);
    cout << dp_ham() << endl;

    N = 5;
    add_edge(1, 0);
    add_edge(0, 2);
    add_edge(2, 1);
    add_edge(0, 3);
    add_edge(3, 4);
    add_edge(3, 2);
    add_edge(3, 1);
    add_edge(2, 4);
    cout << dp_ham() << endl;
*/
    return 0;
}

void dfs(int curr){
    visited[curr] = true;
    cout << curr << " ";
    for(int i = 0; i < N; i++){
        if(graph[curr][i] && !visited[i]){
            dfs(i);
        }
    }
    st.push(curr);
}

// if only 1 graph --> save value of graph1[i][j] & swap
void transpose(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            graph1[i][j] = graph[j][i];
        }   
    }   
}

void dfs2(int curr){
    visited[curr] = true;
    cout << curr << " ";
    for(int i = 0; i < N; i++){
        if(graph1[curr][i] && !visited[i]){
            dfs2(i);
        }
    }
}

void kosaraju(){
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    transpose();    
    for(int i = 0; i < N; i++){
        visited[i] = 0;
    }
    cout << endl;
    cout << "scc" << endl;
    while(!st.empty()){
        int tmp = st.top();
        if(!visited[tmp]){
            dfs2(tmp);
            st.pop();
            cout << endl;
        }
    }
}













