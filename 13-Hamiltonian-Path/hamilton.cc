#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 10
#define MM 100

using namespace std;

int graph[MAX][MAX], N;
bool dp[MAX][MM];
void add_edge(int i, int j){
    graph[i][j] = 1;
    graph[j][i] = 1;
}

void rm_edge(int i, int j){
    graph[j][i] = 0;
    graph[i][j] = 0;
}

bool hamilton(){
    int v[N];
    bool r = false;
    for(int i = 0; i < N; i++){
        v[i] = i;
    }
    do{
        int i;
        for(i = 1; i < N; i++){
            if(graph[v[i-1]][v[i]] == 0)
                break;
        }
        if(i == N - 1 && graph[v[N-1]][v[0]] == 0){
            r = true;
            for(int i = 0; i < N; i++){
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }while(next_permutation(v , v + N));
    
    return r;
}
bool has_hamc();
void print();
bool dp_ham();

int main(){

    N = 4;
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    cout << dp_ham() << endl;

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
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
void print(int p[], int n){
    for(int i = 0; i <= n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
}
bool is_path(int *path, bool *v, int id){
    if(id == N){
        if(graph[path[N-1]][path[0]] > 0)
            return true;
        else 
            return false;
    }
    for(int i = 0; i < N; i++){
        if(!v[i] && graph[path[id-1]][i] == 1){
            v[i] = true;
            path[id] = i;
            if(is_path(path, v, id+1)){
                return true;
            }
            v[i] = false;
        }
    }
    return false;
}

bool has_hamc(){
    bool v[N];
    memset(v, 0, N);
    int path[N];
    for(int i = 0; i < N; i++){
        v[i] = true;
        path[0] = i;
        if(is_path(path, v, 1)){
            for(int i = 0; i < N; i++){
                cout << path[i] << " ";
            }
            cout << endl;
            return true;    
        }
        v[i] = false;
    }
    return false;
}

bool dp_ham(){
    int S = 1 << N;
    memset(dp, 0, S);
    int bm[N];
    for(int i = 0; i < N; i++){
        bm[i] = 1<<i;
        dp[i][bm[i]] = true;
    }
    
    for(int s = 1; s < S; s++){
        for(int v = 0; v < N; v++){
            if(s & bm[v]){
                int subs = s ^ bm[v];
                if(subs == 0) break;
                for(int i = 0; i < N; i++){
                    if((subs & bm[i]) && dp[i][subs] && graph[i][v]){
                        dp[v][s] = true;    
                    }
                }
            }
        }   
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < S; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    for(int j = 0; j < N; j++){
        if(dp[j][S-1] != 0) return true;
    }
    return false;
}














