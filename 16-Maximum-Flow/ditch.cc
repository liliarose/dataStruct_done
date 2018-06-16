/*
ID: your_id_here
TASK: ditch
LANG: C++                 
*/

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
    ofstream fout ("ditch.out");
    ifstream fin ("ditch.in");
    
    int M;
    fin >> M >> N;
    
    for(int i = 0, a, b, c; i < M; i++){
        fin >> a >> b >> c;

    }
    
    cout << maxFlow(1, 4) << endl;
    return 0;
}

bool bfs(int s, int f, int parent[]){
    queue<int> q;
    q.push(s);
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


