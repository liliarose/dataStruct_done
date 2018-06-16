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
};

edge arr[MAX];
edge new_graph[MAX];
int size;
int find(int parent[], int i);
void print(edge arr[MAX], int);
void add_edge(int a, int b, int c);
bool myfunc(edge i, edge j) { return (i.wgt < j.wgt); } 

void kruskal(){
    int parent[MAX];
    memset(parent, -1, sizeof(parent));
    sort(arr, arr + size, myfunc);
    for(int i = 0, count = 0, tmp; count < N-1 && i < size; i++){
        int a = find(parent, arr[i].src);
        int b = find(parent, arr[i].dst);
        if( a != b){
            parent[a] = b;
            new_graph[count] = edge(arr[i].src, arr[i].dst, arr[i].wgt);    
            count++;
        } 
        
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
    kruskal();
    print(new_graph, N - 1);
    return 0;
}

void print(edge arr[], int M){
    for(int i = 0; i < M; i++){
        cout << arr[i].src << " - " << arr[i].dst << "\t" << arr[i].wgt << "\n";
    }
}

int find(int parent[], int i){
    while(parent[i] != -1){
        i = parent[i];
        //cout << "curr i: " << i << endl;
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
    arr[size] = edge(a, b, c);
    size++;
}
