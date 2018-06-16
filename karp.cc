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
    
/*  
    N = 5;
    addEdge(1, 2, 40);
    addEdge(1, 4, 20);
    addEdge(2, 4, 20);
    addEdge(2, 3, 30);
    addEdge(3, 4, 10);
*/
    cout << maxFlow(0, 3) << endl;
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
            if(graph[k][i] && parent[i] == -1){
                q.push(i);
                parent[i] = k;
            }
        }
    }
    return parent[f] != -1;
}

int maxFlow(int s, int f){
    int parent[N], mf = 0;
    initialize(parent, -1);
    while(bfs(s, f, parent)){
        //print(parent);
        int curr = f, tmp = INF;
        while(curr != s){
            if(tmp > graph[parent[curr]][curr]){
                tmp = graph[parent[curr]][curr];
            }
            curr = parent[curr];
        }
        mf += tmp;
        //cout << tmp << " " << mf << endl;
        curr = f;
        while(curr != s){
            graph[parent[curr]][curr] -= tmp;
            graph[curr][parent[curr]] += tmp;
            curr = parent[curr];
        }
        //cout << "kk" << endl;
        initialize(parent, -1);
        //print(parent);
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


